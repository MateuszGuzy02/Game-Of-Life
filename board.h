#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <QTableWidget>
#include <QObject>
#include <QColor>

class Board : public QObject
{
    Q_OBJECT

signals:

    void livingCellsCountUpdated(int count) const;

private:

    std::vector<std::vector<char>> cells;

    int width = 0;
    int height = 0;

    QColor liveCellColor = Qt::black;
    QColor deadCellColor = Qt::white;

public:

    Board(int w, int h);

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    bool getCell(int x, int y) const;
    void setCell(int x, int y, bool value);
    const std::vector<std::vector<char>>& getCells() const { return cells; }
    void setCells(std::vector<std::vector<char>>& newCells);
    void initializeBoard();
    void initializeBoardWithSeed(unsigned int seed);
    void resizeBoard(int newWidth, int newHeight);
    void nextGeneration();
    void printBoard(QTableWidget* tableWidget) const;
    void clear();

    void setLiveCellColor(const QColor& color);
    void setDeadCellColor(const QColor& color);

    QColor getLiveCellColor() const { return liveCellColor; }
    QColor getDeadCellColor() const { return deadCellColor; }

    int countLivingCells() const;
    bool isAlive(const int x, const int y) const;
    void toggleCellState(int row, int col);

};
#endif // BOARD_H
