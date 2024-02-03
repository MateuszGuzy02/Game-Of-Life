#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "board.h"
#include <chrono>
#include <thread>
#include <QObject>
#include <QTableWidgetItem>
#include <QCoreApplication>
#include <QMessageBox>
#include <QTimer>

class GameOfLife: public QObject
{
    Q_OBJECT

signals:
    void boardUpdated();
    void livingCellsCountUpdated(int count);
    void totalStepsUpdated(int steps);

private:
    Board board;
    bool isRunning;
    unsigned int randomSeed;
    bool automaticStep;
    bool stopRequested;
    bool isLoadingFromFile;
    unsigned int totalSteps;
    int interval;
    bool isStepButtonClicked;
    std::vector<std::vector<char>> previousBoardState;
    QTimer *timer;



public:
    GameOfLife(int width, int height);

    Board& getBoard() { return board; }
    int getTotalSteps() const { return totalSteps; }
    void increaseTotalSteps(unsigned int steps = 1);
    void start();
    void stop();
    void step();
    void setBoardSize(int width, int height);
    void setRandomSeed(unsigned int seed);
    void setInterval(int value) { interval = value; }
    void setIsLoadingFromFile(bool value) { isLoadingFromFile = value; }
    void setTotalSteps(int steps);
    int getInterval() { return interval; }
    void resizeBoard(int width, int height);
    bool getIsRunning() const { return isRunning; }
    void clearBoard();
    void pause();
    void resume();
    void handleStepButtonClick();
    void handleTimerTimeout();


};
#endif // GAMEOFLIFE_H
