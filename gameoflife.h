#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "board.h"
#include <QObject>
#include <QTableWidgetItem>
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
    std::vector<std::vector<char>> previousBoardState;
    QTimer *timer;

    bool isRunning;
    bool automaticStep;
    bool stopRequested;
    bool isLoadingFromFile;
    bool isStepButtonClicked;
    int interval;
    unsigned int randomSeed;
    unsigned int totalSteps;

public:
    GameOfLife(int width, int height);

    void setBoardSize(int width, int height) { board.resizeBoard(width, height); }
    void setRandomSeed(unsigned int seed);
    void setInterval(int value) { interval = value; }
    void setIsLoadingFromFile(bool value) { isLoadingFromFile = value; }
    void setTotalSteps(int steps);

    int getTotalSteps() const { return totalSteps; }
    int getInterval() { return interval; }
    bool getIsRunning() const { return isRunning; }
    Board& getBoard() { return board; }


    void start();
    void stop();
    void step();
    void clearBoard();
    void pause();
    void resume();
    void handleStepButtonClick();
    void handleTimerTimeout();
    void resizeBoard(int width, int height);
    void increaseTotalSteps(unsigned int steps = 1);

};
#endif // GAMEOFLIFE_H
