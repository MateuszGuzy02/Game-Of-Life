#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "board.h"

#include <QObject>
#include <QTableWidgetItem>
#include <QCoreApplication>
#include <QMessageBox>

class GameOfLife: public QObject {
    Q_OBJECT


signals:
    void boardUpdated();

private:

    Board board;
    bool isRunning;
    unsigned int randomSeed;
    bool automaticStep;
    bool stopRequested;
    unsigned int totalSteps;

    bool isStepButtonClicked;
    std::vector<std::vector<int>> previousBoardState;

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
    void resizeBoard(int width, int height);
    bool getIsRunning() const { return isRunning; }
    void displayBoard();
    void clearBoard();

public slots:
    void pause();
    void resume();

};

#endif // GAMEOFLIFE_H
