#include "gameoflife.h"
#include <chrono>
#include <thread>


using namespace std;

GameOfLife::GameOfLife(int width, int height) : board(width, height), isRunning(false), randomSeed(0), isStepButtonClicked(false)
{
    clearBoard();
}

void GameOfLife::start()
{
    qDebug() << "Rozpoczynam symulację z interwałem:" << interval;
    isRunning = true;
    automaticStep = true;  // Ustawienie automatycznego kroku
    stopRequested = false; // Inicjalizacja flagi
    totalSteps = 0;

    emit totalStepsUpdated(totalSteps);  // Emituj sygnał z aktualną liczbą kroków


    previousBoardState = board.getCells();  // Inicjalizacja poprzedniego stanu planszy

    while (isRunning && !stopRequested)
    {
        if (automaticStep)
        {
            step();  // Wykonaj krok symulacji
            emit boardUpdated();

            QCoreApplication::processEvents(); // Pozwól na aktualizacje interfejsu graficznego
            std::this_thread::sleep_for(std::chrono::milliseconds(getInterval())); // Opcjonalne opóźnienie
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

        if (aliveCount == 0)        // Jeśli liczba komórek żywych wynosi 0, zatrzymaj symulację
        {
            stop();
            QMessageBox::information(nullptr, "Koniec symulacji", "Symulacja zakończona po " + QString::number(getTotalSteps()) + " krokach.");
            break;
        }

        else if (previousBoardState == board.getCells()) // Sprawdź, czy plansza powtarza się
        {
            stop();
            QMessageBox::information(nullptr, "Koniec symulacji", "Plansza osiągnęła stan stabilny. Symulacja zatrzymana po " + QString::number(getTotalSteps()) + " krokach.");
            break;
        }

        previousBoardState = board.getCells();  // Zaktualizuj poprzedni stan planszy

    }

}

void GameOfLife::step()
{
    board.nextGeneration();
    increaseTotalSteps();

    int livingCellsCount = board.countLivingCells();
    emit livingCellsCountUpdated(livingCellsCount);  // Emituj sygnał z aktualną liczbą żyjących komórek
    emit totalStepsUpdated(getTotalSteps());
}

void GameOfLife::pause()
{
    isRunning = false;      // Zatrzymywanie symulacji
    automaticStep = false;  // Zatrzymaj automatyczny krok symulacji
}

void GameOfLife::resume()
{
    if (!isRunning) {
        isRunning = true;
        automaticStep = true;
        stopRequested = false;
        start();  // Uruchom ponownie symulację
    }
}

void GameOfLife::stop()
{
    isRunning = false;     // Zakończenie symulacji

}

void GameOfLife::setBoardSize(int width, int height)
{
    board.resizeBoard(width, height);
}

void GameOfLife::setRandomSeed(unsigned int seed)
{
    randomSeed = seed;
    board.clear();
    board.initializeBoardWithSeed(randomSeed);

    int livingCellsCount = board.countLivingCells(); // Oblicz liczbę żywych komórek
    emit livingCellsCountUpdated(livingCellsCount); // Emituj sygnał z aktualną liczbą żywych komórek
}

void GameOfLife::resizeBoard(int width, int height)
{
    board.resizeBoard(width, height);
}

void GameOfLife::displayBoard()
{

    if (!isRunning && !isStepButtonClicked) {
        step();
        emit boardUpdated();  // Emituj sygnał po każdym kroku
        isStepButtonClicked = true;
    } else {
        isStepButtonClicked = false;
    }
}

void GameOfLife::clearBoard()
{
    qDebug() << "Clearing board...";
    board.clear();
    board.resizeBoard(board.getWidth(), board.getHeight());
    qDebug() << "Board cleared";

    board.countLivingCells();
}

void GameOfLife::increaseTotalSteps(unsigned int steps)
{
    totalSteps += steps;
    emit totalStepsUpdated(totalSteps);  // Emituj sygnał z aktualną liczbą kroków
}

