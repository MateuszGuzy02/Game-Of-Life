#ifndef BOARD_H
#define BOARD_H
#include <QColor>
#include <QObject>
#include <QTableWidget>
#include <vector>

class Board : public QObject
{
    Q_OBJECT

signals:
    void livingCellsCountUpdated(int count) const;

private:
    std::vector<std::vector<char>> cells; // Macierz komórek

    int width;
    int height;

    QColor liveCellColor = Qt::black;
    QColor deadCellColor = Qt::white;

public:
    Board(int w, int h);

    void setCell(int x, int y, bool value) { cells[x][y] = value ? 1 : 0; }
    void setLiveCellColor(const QColor &color) { liveCellColor = color; }
    void setDeadCellColor(const QColor &color) { deadCellColor = color; }
    void setCells(std::vector<std::vector<char>> &newCells);

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    bool getCell(int x, int y) const { return cells[x][y] == 1; }
    const std::vector<std::vector<char>> &getCells() const { return cells; }
    QColor getLiveCellColor() const { return liveCellColor; }
    QColor getDeadCellColor() const { return deadCellColor; }

    void initializeBoard();
    void initializeBoardWithSeed(unsigned int seed);
    void resizeBoard(int newWidth, int newHeight);
    void nextGeneration();
    void printBoard(QTableWidget *tableWidget) const;
    void toggleCellState(int row, int col);
    void clear();
    int countLivingCells() const;
    bool isAlive(const int x, const int y) const;
};
#endif // BOARD_H
