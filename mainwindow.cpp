#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Inicjalizacja obiektu GameOfLife
    game = new GameOfLife(initialWidth, initialHeight);


    // Połącz sygnały z odpowiednimi slotami
    connect(ui->stepButton, &QPushButton::clicked, game, &GameOfLife::handleStepButtonClick);

    // Emitowanie sygnału do odświeżania planszy
    connect(game, &GameOfLife::boardUpdated, this, &MainWindow::updateTable);


    // Połączenie zmiany wartości spinboxów z odpowiednimi slotami w GameOfLife
    connect(ui->columnBox, SIGNAL(valueChanged(int)), game, SLOT(onColumnChanged(int)));
    connect(ui->rowBox, SIGNAL(valueChanged(int)), game, SLOT(onRowChanged(int)));


    connect(ui->speedDial, SIGNAL(valueChanged(int)), ui->speedLCD, SLOT(display(int)));
    speedLCD = ui->speedLCD;
    speedLCD->setSegmentStyle(QLCDNumber::Flat);  // Ustaw styl segmentu
    speedLCD->setStyleSheet("QLCDNumber { color: black; background-color: lightGray; }");  // Ustaw kolor tekstu i tła
    ui->LifeCells->setSegmentStyle(QLCDNumber::Flat);  // Ustaw styl segmentu
    ui->LifeCells->setStyleSheet("QLCDNumber { color: black; background-color: lightGray; }");  // Ustaw kolor tekstu i tła
    ui->stepsLCD->setSegmentStyle(QLCDNumber::Flat);  // Ustaw styl segmentu
    ui->stepsLCD->setStyleSheet("QLCDNumber { color: black; background-color: lightGray; }");  // Ustaw kolor tekstu i tła

    connect(game, &GameOfLife::livingCellsCountUpdated, this, &MainWindow::updateLivingCellsLCD);
    connect(&game->getBoard(), &Board::livingCellsCountUpdated, this, &MainWindow::updateLivingCellsLCD);
    connect(game, &GameOfLife::totalStepsUpdated, this, &MainWindow::updateTotalStepsLCD);

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

    // Ukryj numerowanie wierszy i kolumn
    ui->gameTable->verticalHeader()->setVisible(false);
    ui->gameTable->horizontalHeader()->setVisible(false);
    // Ustawienie rozciągliwego rozmiaru kolumn i wierszy
    ui->gameTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->gameTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Inicjalizacja komórek tabeli
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);  // Blokada edycji komórek
            ui->gameTable->setItem(i, j, item);
        }
    }

    // Aktualizacja zawartości tabeli
    updateTable();
}

void MainWindow::updateTable() {
    game->getBoard().printBoard(ui->gameTable);
    ui->gameTable->viewport()->update();
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
    updateTable();
}


void MainWindow::on_randomButton_clicked()
{
    game->getBoard().initializeBoard();
    updateTable();
}


void MainWindow::on_clearButton_clicked()
{
    game->clearBoard();
    updateTable();
}


void MainWindow::on_startButton_clicked()
{
    disconnect(ui->startButton, &QPushButton::clicked, game, &GameOfLife::start);  // Odłącz istniejące połączenie
    connect(ui->startButton, &QPushButton::clicked, game, &GameOfLife::start);
    if (!game->getIsRunning())
    {
        int interval = ui->speedDial->value();
        speedLCD->display(interval);
        game->setInterval(interval);
        ui->startButton->setEnabled(false);  // Wyłącz przycisk start
        game->start();
        ui->startButton->setEnabled(true);   // Włącz przycisk start po zakończeniu symulacji
    }

}

void MainWindow::updateLivingCellsLCD(int count)
{
    ui->LifeCells->display(count);  // Ustaw wartość QLCDNumber na aktualną liczbę żyjących komórek
}

void MainWindow::updateTotalStepsLCD(int steps)
{
    ui->stepsLCD->display(steps);  // Ustaw wartość QLCDNumber na aktualną liczbę kroków
}


void MainWindow::on_pauseResumeButton_clicked()
{

}


