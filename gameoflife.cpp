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

    // Inicjalizacja poprzedniego stanu planszy
    previousBoardState = board.getCells();

    while (isRunning && !stopRequested)
    {
        if (automaticStep) {
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

        // Zaktualizuj poprzedni stan planszy
        previousBoardState = board.getCells();

    }

}

void GameOfLife::step()
{
    //displayBoard();
    board.nextGeneration();
    increaseTotalSteps();

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
}

void GameOfLife::resizeBoard(int width, int height)
{
    board.resizeBoard(width, height);
}

void GameOfLife::increaseTotalSteps(unsigned int steps)
{
    totalSteps += steps;
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
    board.clear();
    board.resizeBoard(board.getWidth(), board.getHeight());
}
