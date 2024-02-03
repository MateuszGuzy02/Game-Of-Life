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


    // Zatrzymanie oraz wznowienie symulacji
    connect(ui->pauseButton, &QPushButton::clicked, game, &GameOfLife::pause);
    connect(ui->resumeButton, &QPushButton::clicked, game, &GameOfLife::resume);

    // Plik
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveToFile);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFromFile);


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
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
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
    if (!game->getIsRunning())
    {
        // Odłącz istniejące połączenie
        disconnect(ui->startButton, &QPushButton::clicked, game, &GameOfLife::start);

        // Ustaw interwał i wyświetl na LCD
        int interval = ui->speedDial->value();
        speedLCD->display(interval);
        game->setInterval(interval);

        // Uruchom symulację
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


void MainWindow::on_pauseButton_clicked()
{
    game->pause();
}


void MainWindow::on_resumeButton_clicked()
{
    game->resume();
}

void MainWindow::saveToFile()
{
    // Zapisz bieżącą wartość do obiektu GameOfLife przed zapisaniem do pliku
    game->setInterval(ui->speedDial->value());
    game->setTotalSteps(ui->stepsLCD->value());

    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Game State"), QString(), tr("Text Files (*.txt);;All Files (*)"));

    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);

            // Zapisz szerokość i wysokość planszy
            out << "Width: " << game->getBoard().getWidth() << "\n";
            out << "Height: " << game->getBoard().getHeight() << "\n";

            // Zapisz TotalSteps
            out << "TotalSteps: " << game->getTotalSteps() << "\n";

            // Zapisz interwał czasowy
            out << "Interval: " << game->getInterval() << "\n";

            // Zapisz żywe i martwe komórki
            out << "BoardState:\n";
            const auto &cells = game->getBoard().getCells();
            for (const auto &row : cells)
            {
                for (int cell : row)
                {
                    out << cell << " ";
                }
                out << "\n";
            }

            file.close();
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not save file."));
        }
    }
}


void MainWindow::openFromFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Game State"), QString(), tr("Text Files (*.txt);;All Files (*)"));

    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);

            // Wczytaj szerokość i wysokość planszy
            int width = 0, height = 0, interval = 0, totalSteps = 0;
            QString line;

            while (!in.atEnd())
            {
                line = in.readLine().trimmed();
                if (line.isEmpty())
                    continue;

                QStringList tokens = line.split(":");
                if (tokens.size() != 2)
                    continue;

                QString key = tokens[0].trimmed();
                QString value = tokens[1].trimmed();

                if (key == "Width")
                {
                    width = value.toInt();
                    ui->rowBox->setValue(width);  // Aktualizuj wartość w spinbox szerokości
                }
                else if (key == "Height")
                {
                    height = value.toInt();
                    ui->columnBox->setValue(height);  // Aktualizuj wartość w spinbox wysokości
                }
                else if (key == "TotalSteps")
                {
                    totalSteps = value.toInt();
                    // Ustaw totalSteps w obiekcie gry
                    game->setTotalSteps(totalSteps);
                }
                else if (key == "Interval")
                {
                    interval = value.toInt();
                    // Zastosuj wczytane wartości do obiektu gry
                    game->resizeBoard(width, height);
                    game->setInterval(interval);

                    // Ustaw flagę isLoadingFromFile przed wywołaniem start()
                    game->setIsLoadingFromFile(true);

                    // Aktualizuj interfejs i informacje o stanie gry
                    updateTable();
                    ui->speedDial->setValue(game->getInterval());
                }
                else if (key == "BoardState")
                {
                    // Rozdziel wartości i ustaw komórki w obiekcie gry
                    std::vector<std::vector<char>> cells;
                    for (int i = 0; i < height; ++i)
                    {
                        line = in.readLine().trimmed();
                        QStringList cellValues = line.split(" ", Qt::SkipEmptyParts);
                        std::vector<char> row;
                        for (const QString &cellValue : cellValues)
                        {
                            row.push_back(cellValue.toInt());
                        }
                        cells.push_back(row);
                    }

                    // Ustaw komórki na planszy
                    game->getBoard().setCells(cells);
                    updateTable();  // Dodaj tę linijkę, aby od razu zaktualizować planszę po wczytaniu danych

                    break; // Zakończ pętlę, ponieważ już wczytaliśmy komórki planszy
                }
            }

            file.close();
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file."));
        }
    }
}



