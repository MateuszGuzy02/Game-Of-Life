#include "gameoflife.h"

using namespace std;

GameOfLife::GameOfLife(int width, int height) : board(width, height), isRunning(false), isStepButtonClicked(false), randomSeed(0), totalSteps(0)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GameOfLife::handleTimerTimeout);
    isLoadingFromFile = false;
    clearBoard();
}

void GameOfLife::start()
{
    if (!isLoadingFromFile)
    {
        timer->start(getInterval());        // Ustawienie interwału timera

        totalSteps = 0;                     // Resetowanie totalSteps tylko jeśli nie wczytujesz z pliku
        emit totalStepsUpdated(totalSteps);
    }

    isRunning = true;
    automaticStep = true;
    stopRequested = false;

    previousBoardState = board.getCells();

    timer->start(getInterval());            // Ustawienie interwału timera na wartość getInterval()
}

void GameOfLife::handleTimerTimeout()
{

    if (isRunning && !stopRequested)
    {

        if (automaticStep)
        {
            step();
            emit boardUpdated();
        }

        int aliveCount = 0;
        auto cells = board.getCells();

        for (const auto& row : cells)
        {
            for (int cell : row)
            {
                if (cell == 1)
                    aliveCount++;
            }
        }

        if (aliveCount == 0)
        {
            stop();
            QMessageBox::information(nullptr, "Simulation End", "Simulation completed after " + QString::number(getTotalSteps()) + " steps.");
        }
        else if (previousBoardState == board.getCells())
        {
            stop();
            QMessageBox::information(nullptr, "Simulation End", "The board has reached a stable state. Simulation stopped after " + QString::number(getTotalSteps()) + " steps.");
        }

        previousBoardState = board.getCells();

    }
    else
        timer->stop();
}

void GameOfLife::step()
{
    board.nextGeneration();
    increaseTotalSteps();

    int livingCellsCount = board.countLivingCells();
    emit livingCellsCountUpdated(livingCellsCount);         // Emituj sygnał z aktualną liczbą żyjących komórek
    emit totalStepsUpdated(getTotalSteps());
}

void GameOfLife::handleStepButtonClick()
{
    if (!isRunning && !isStepButtonClicked)
    {
        step();
        emit boardUpdated();            // Emituj sygnał po każdym kroku
        isStepButtonClicked = true;
    }
    else
        isStepButtonClicked = false;
}

void GameOfLife::pause()
{
    isRunning = false;              // Zatrzymywanie symulacji
    automaticStep = false;          // Zatrzymaj automatyczny krok symulacji
}

void GameOfLife::resume()
{
    if (!isRunning)
    {
        isRunning = true;
        automaticStep = true;
        stopRequested = false;

        timer->start(getInterval());     // Uruchom ponownie symulację
    }
}

void GameOfLife::stop()
{
    isRunning = false;     // Zakończenie symulacji
    timer->stop();         // Zatrzymaj timer

    QString message = QString("Simulation stopped after %1 steps.\nLiving cells: %2")   // Wyświetlenie komunikatu z informacją o liczbie kroków i żywych komórkach
                          .arg(totalSteps)
                          .arg(board.countLivingCells());

    QMessageBox::information(nullptr, "Simulation Stopped", message);
}

void GameOfLife::setRandomSeed(unsigned int seed)
{
    randomSeed = seed;
    board.clear();
    board.initializeBoardWithSeed(randomSeed);

    int livingCellsCount = board.countLivingCells();        // Oblicz liczbę żywych komórek
    emit livingCellsCountUpdated(livingCellsCount);         // Emituj sygnał z aktualną liczbą żywych komórek
}

void GameOfLife::resizeBoard(int width, int height)
{
    board.resizeBoard(width, height);
}

void GameOfLife::clearBoard()
{
    board.clear();
    board.resizeBoard(board.getWidth(), board.getHeight());
    board.countLivingCells();
    totalSteps = 0;
    emit totalStepsUpdated(totalSteps);
}

void GameOfLife::increaseTotalSteps(unsigned int steps)
{
    totalSteps += steps;
    emit totalStepsUpdated(totalSteps);         // Emituj sygnał z aktualną liczbą kroków
}

void GameOfLife::setTotalSteps(int steps)
{
    totalSteps = steps;
    emit totalStepsUpdated(totalSteps);         // Emituj sygnał o zmianie liczby kroków
}

void GameOfLife::saveToFile()
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, tr("Save Game State"), QString(), tr("Text Files (*.txt);;All Files (*)"));

    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);

            out << "Width: " << board.getWidth() << "\n";                        // Zapisz szerokość i wysokość planszy
            out << "Height: " << board.getHeight() << "\n";
            out << "TotalSteps: " << totalSteps << "\n";                         // Zapisz TotalSteps
            out << "Interval: " << interval << "\n";                             // Zapisz interwał czasowy
            out << "LiveCellColor: " << board.getLiveCellColor().name() << "\n"; // Zapisz kolory komórek
            out << "DeadCellColor: " << board.getDeadCellColor().name() << "\n";
            out << "BoardState:\n";                                             // Zapisz żywe i martwe komórki

            const auto& cells = board.getCells();
            for (const auto& row : cells)
            {
                for (int cell : row)
                    out << cell << " ";
                out << "\n";
            }
            file.close();
        }
        else
            QMessageBox::critical(nullptr, tr("Error"), tr("Could not save file."));
    }
}

void GameOfLife::openFromFile()
{
    isLoadingFromFile = true;
    QString filePath = QFileDialog::getOpenFileName(nullptr, tr("Open Game State"), QString(), tr("Text Files (*.txt);;All Files (*)"));

    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);

            // Wczytaj szerokość i wysokość planszy
            int width = 0, height = 0, interval = 0, loadedTotalSteps = 0;
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
                }
                else if (key == "Height")
                {
                    height = value.toInt();
                }

                emit boardSizeChanged(height, width);   // Emituj sygnał informujący o zmianie rozmiaru planszy


                if (key == "TotalSteps")
                {
                    loadedTotalSteps = value.toInt();
                    setTotalSteps(loadedTotalSteps);
                }
                else if (key == "Interval")
                {
                    interval = value.toInt();
                    setInterval(interval);
                    emit intervalUpdated(interval);
                }
                else if (key == "LiveCellColor")
                {
                    QColor liveCellColor(value);
                    board.setLiveCellColor(liveCellColor);
                }
                else if (key == "DeadCellColor")
                {
                    QColor deadCellColor(value);
                    board.setDeadCellColor(deadCellColor);
                }
                else if (key == "BoardState")
                {
                    std::vector<std::vector<char>> cells;
                    for (int i = 0; i < height; ++i)
                    {
                        line = in.readLine().trimmed();
                        QStringList cellValues = line.split(" ", Qt::SkipEmptyParts);
                        std::vector<char> row;

                        for (const QString& cellValue : cellValues)
                            row.push_back(cellValue.toInt());

                        cells.push_back(row);
                    }

                    board.resizeBoard(width, height);   // Zmiana rozmiaru planszy przed ustawieniem komórek
                    board.setCells(cells);              // Ustaw komórki na planszy
                    emit boardUpdated();                // Emituj sygnał aktualizacji planszy

                    break;                              // Zakończ pętlę, ponieważ już wczytaliśmy komórki planszy
                }
            }

            file.close();
        }
        else
            QMessageBox::critical(nullptr, tr("Error"), tr("Could not open file."));
    }
}
