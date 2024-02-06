#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->startButton->setEnabled(false);
    ui->resumeButton->setEnabled(false);
    ui->pauseButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
    ui->stepButton->setEnabled(false);

    // Inicjalizacja obiektu GameOfLife
    game = new GameOfLife(initialWidth, initialHeight);


    // Połącz sygnały z odpowiednimi slotami
    connect(ui->stepButton, &QPushButton::clicked, game, &GameOfLife::handleStepButtonClick);

    // Emitowanie sygnału do odświeżania planszy
    connect(game, &GameOfLife::boardUpdated, this, &MainWindow::updateTable);


    connect(ui->speedDial, SIGNAL(valueChanged(int)), ui->speedLCD, SLOT(display(int)));
    speedLCD = ui->speedLCD;
    speedLCD->setSegmentStyle(QLCDNumber::Flat);  // Ustaw styl segmentu


    ui->LifeCells->setSegmentStyle(QLCDNumber::Flat);  // Ustaw styl segmentu

    ui->stepsLCD->setSegmentStyle(QLCDNumber::Flat);  // Ustaw styl segmentu

    connect(game, &GameOfLife::livingCellsCountUpdated, this, &MainWindow::updateLivingCellsLCD);
    connect(&game->getBoard(), &Board::livingCellsCountUpdated, this, &MainWindow::updateLivingCellsLCD);
    connect(game, &GameOfLife::totalStepsUpdated, this, &MainWindow::updateTotalStepsLCD);


    // Zatrzymanie oraz wznowienie symulacji
    connect(ui->pauseButton, &QPushButton::clicked, game, &GameOfLife::pause);
    connect(ui->resumeButton, &QPushButton::clicked, game, &GameOfLife::resume);

    // Plik
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveToFile);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFromFile);

    connect(game, &GameOfLife::boardSizeChanged, this, &MainWindow::onBoardSizeChanged);
    connect(game, &GameOfLife::totalStepsUpdated, this, &MainWindow::updateTotalSteps);
    connect(game, &GameOfLife::intervalUpdated, this, &MainWindow::updateIntervalLCD);

    // Inicjalizacja tabeli
    setupTable(initialWidth, initialHeight);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game; // Zwolnienie pamięci po obiekcie GameOfLife
}

void MainWindow::setupTable(int width, int height)
{
    ui->gameTable->setRowCount(height);
    ui->gameTable->setColumnCount(width);


    ui->gameTable->verticalHeader()->setVisible(false);                 // Ukryj numerowanie wierszy i kolumn
    ui->gameTable->horizontalHeader()->setVisible(false);


    ui->gameTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);          // Ustawienie rozciągliwego rozmiaru kolumn i wierszy
    ui->gameTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);  // Blokada edycji komórek
            ui->gameTable->setItem(i, j, item);
        }
    }

    updateTable();          // Aktualizacja zawartości tabeli
}

void MainWindow::updateTable() {
    game->getBoard().printBoard(ui->gameTable);
    ui->gameTable->viewport()->update();
}


void MainWindow::saveToFile()
{
    game->saveToFile();
}

void MainWindow::openFromFile()
{
    game->openFromFile();
    ui->startButton->setEnabled(true);
    ui->stepButton->setEnabled(true);
    updateTable();
}

void MainWindow::onBoardSizeChanged(int height, int width)
{
    ui->rowBox->setValue(height);
    ui->columnBox->setValue(width);
}

void MainWindow::updateTotalSteps(int steps)
{
    ui->stepsLCD->display(steps);
}


void MainWindow::on_actionColorLivingCells_triggered()
{
    QColor chosenColor = QColorDialog::getColor(Qt::white, this, "Choose Color");

    if (chosenColor.isValid())
    {
        game->getBoard().setLiveCellColor(chosenColor);  // Przekaż kolor do obiektu Board
        updateTable();
    }
}

void MainWindow::on_actionColor_of_dead_cells_triggered()
{
    QColor chosenColor = QColorDialog::getColor(Qt::white, this, "Choose Color");

    if (chosenColor.isValid())
    {
        game->getBoard().setDeadCellColor(chosenColor);  // Przekaż kolor do obiektu Board
        updateTable();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    QMessageBox::StandardButton resBtn = QMessageBox::question(
        this, "Confirm Closure", "Are you sure you want to close the program?",
        QMessageBox::No | QMessageBox::Yes,
        QMessageBox::Yes);

    if (resBtn != QMessageBox::Yes)
        event->ignore();
    else
        event->accept();
}

void MainWindow::on_startButton_clicked()
{
    if (!game->getIsRunning())
    {
        disconnect(ui->startButton, &QPushButton::clicked, game, &GameOfLife::start);    // Odłącz istniejące połączenie

        int interval = ui->speedDial->value();      // Ustaw interwał i wyświetl na LCD
        speedLCD->display(interval);
        game->setInterval(interval);

        game->start();
        ui->startButton->setEnabled(false);
        ui->pauseButton->setEnabled(true);
        ui->stopButton->setEnabled(true);
        ui->stepButton->setEnabled(false);
    }
}

void MainWindow::on_stopButton_clicked()
{
    game->stop();
    ui->stopButton->setEnabled(false);
    ui->stepButton->setEnabled(false);
    ui->startButton->setEnabled(false);
    ui->pauseButton->setEnabled(false);
    ui->resumeButton->setEnabled(false);
}

void MainWindow::on_pauseButton_clicked()
{
    game->pause();
    ui->pauseButton->setEnabled(false);
    ui->stepButton->setEnabled(true);
    ui->resumeButton->setEnabled(true);
}


void MainWindow::on_resumeButton_clicked()
{
    game->resume();
    ui->resumeButton->setEnabled(false);
    ui->pauseButton->setEnabled(true);
    ui->stepButton->setEnabled(false);
}

void MainWindow::on_stepButton_clicked()
{
    game->handleStepButtonClick();
    updateTable();
}

void MainWindow::on_rowBox_valueChanged(int newWidth)
{
    setupTable(newWidth, ui->columnBox->value());
    game->getBoard().resizeBoard(newWidth, game->getBoard().getHeight());
    updateTable();
}

void MainWindow::on_columnBox_valueChanged(int newHeight)
{
    setupTable(ui->rowBox->value(), newHeight);
    game->getBoard().resizeBoard(game->getBoard().getWidth(), newHeight);
    updateTable();
}


void MainWindow::on_setSeedBox_valueChanged(int seed)
{
    game->setRandomSeed(static_cast<unsigned int>(seed));
    ui->startButton->setEnabled(true);
    ui->stepButton->setEnabled(true);
    ui->clearButton->setEnabled(true);
    updateTable();
}


void MainWindow::on_randomButton_clicked()
{
    game->getBoard().initializeBoard();
    ui->startButton->setEnabled(true);
    ui->stepButton->setEnabled(true);
    ui->clearButton->setEnabled(true);
    updateTable();
}


void MainWindow::on_clearButton_clicked()
{
    game->clearBoard();
    updateTable();
}

void MainWindow::updateLivingCellsLCD(int count)
{
    ui->LifeCells->display(count);          // Ustaw wartość QLCDNumber na aktualną liczbę żyjących komórek
}

void MainWindow::updateTotalStepsLCD(int steps)
{
    ui->stepsLCD->display(steps);           // Ustaw wartość QLCDNumber na aktualną liczbę kroków
}

void MainWindow::updateIntervalLCD(int interval)
{
    ui->speedLCD->display(interval);        // Ustaw wartość QLCDNumber na aktualny interwał
    ui->speedDial->setValue(interval);
}

void MainWindow::on_speedDial_sliderReleased()
{
    int value = ui->speedDial->value();
    game->setInterval(value);
}

