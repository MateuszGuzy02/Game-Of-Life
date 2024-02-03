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
