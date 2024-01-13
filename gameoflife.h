#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "board.h"
#include "timer.h"
#include <QObject>
#include <QTableWidgetItem>

class GameOfLife: public QObject {
    Q_OBJECT
private:

    Board board;
    bool isRunning;
    unsigned int randomSeed;
    bool automaticStep;
    int totalSteps;

    bool isStepButtonClicked;

public:

    GameOfLife(int width, int height) : board(width, height), isRunning(false), randomSeed(0), isStepButtonClicked(false) {}

    Timer timer;
    Board& getBoard() { return board; }
    int getTotalSteps() const { return totalSteps; }
    void increaseTotalSteps(int steps = 1) { totalSteps += steps; }  // Funkcja zwiększająca licznik kroków

    void start();
    void pause();
    void resume();
    void stop();
    void step();
    void setBoardSize(int width, int height);
    void setRandomSeed(unsigned int seed);
    void resizeBoard(int width, int height);
    bool getIsRunning() const { return isRunning; }
    void displayBoard() const;
    void onStepButtonClicked();

    void resetStepButtonState();

signals:
    void stepClicked();

};

#endif // GAMEOFLIFE_H
