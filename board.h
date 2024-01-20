#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <QTableWidget>
#include <QObject>

class Board : public QObject
{
    Q_OBJECT

signals:

    void livingCellsCountUpdated(int count) const;

private:

    std::vector<std::vector<char>> cells;
    int width = 0;
    int height = 0;

public:

    Board(int w, int h);

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    bool getCell(int x, int y) const;
    void setCell(int x, int y, bool value);
    const std::vector<std::vector<char>>& getCells() const { return cells; }
    void initializeBoard();
    void initializeBoardWithSeed(unsigned int seed);
    void resizeBoard(int newWidth, int newHeight);
    void nextGeneration();
    void printBoard(QTableWidget* tableWidget) const;
    void clear();

    int countLivingCells() const;
    bool isAlive(const int x, const int y) const;

};
#endif // BOARD_H
