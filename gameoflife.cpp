#include "gameoflife.h"
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

void GameOfLife::start()
{
    isRunning = true;
    automaticStep = true;  // Ustawienie automatycznego kroku
    timer.start();

    do {
        if (automaticStep) {
            step();  // Wykonaj krok symulacji
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
            displayBoard();
            stop();
            cout << "No live cells. Simulation stopped after " << getTotalSteps() << " Steps." << endl;
            break;
        }


    } while (isRunning);  // Pętla do-while sprawia, że pętla wykonuje się co najmniej raz

    board.clear();
}

void GameOfLife::step()
{
    displayBoard();
    board.nextGeneration();
    increaseTotalSteps();
}

void GameOfLife::pause()
{
    isRunning = false;      // Zatrzymywanie symulacji
    timer.pause();
}

void GameOfLife::resume()
{
    isRunning = true;      // Wznowienie symulacji
    timer.resume();
}

void GameOfLife::stop()
{
    isRunning = false;     // Zakończenie symulacji
    timer.stop();
}

void GameOfLife::setBoardSize(int width, int height)
{
    board.resizeBoard(width, height);
}

void GameOfLife::setRandomSeed(unsigned int seed)
{
    randomSeed = seed;
    board.initializeBoardWithSeed(randomSeed);
}

void GameOfLife::resizeBoard(int width, int height)
{
    board.resizeBoard(width, height);
}

void GameOfLife::displayBoard() const
{
    timer.getRunning();
    //board.printBoard();
    //this_thread::sleep_for(chrono::milliseconds(timer.getInterval()));
}

void GameOfLife::onStepButtonClicked() {
    if (!isRunning && !isStepButtonClicked) {
        step();
        displayBoard();
        isStepButtonClicked = true;
    } else {
        isStepButtonClicked = false;
    }
}

void GameOfLife::resetStepButtonState() {
    isStepButtonClicked = false;
}
