#include "board.h"
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

Board::Board(int w, int h)
    : width(w)
    , height(h)
{
    initializeBoard();
}

void Board::initializeBoard()
{
    mt19937 rng(
        static_cast<unsigned int>(time(nullptr))); // Inicjalizacja generatora liczb pseudolosowych
    uniform_int_distribution<int> dist(0, 1);      // Dystrybucja dla losowania liczb 0 lub 1

    cells.resize(height, vector<char>(width, 0));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j)
            cells[i][j] = static_cast<char>(dist(rng)); // Losowa wartość: 0 lub 1
    }

    int livingCellsCount = countLivingCells();
    emit livingCellsCountUpdated(livingCellsCount);
}

void Board::printBoard(QTableWidget *tableWidget) const
{
    const auto &cells = getCells();

    for (int i = 0; i < getHeight(); ++i) {
        for (int j = 0; j < getWidth(); ++j) {
            QTableWidgetItem *item = tableWidget->item(i, j);
            if (item) {
                if (cells[i][j] == 1)
                    item->setBackground(QBrush(liveCellColor));
                else
                    item->setBackground(QColor(deadCellColor));
            }
        }
    }
}

void Board::resizeBoard(int newWidth, int newHeight)
{
    width = newWidth;
    height = newHeight;

    cells.assign(height,
                 vector<char>(width,
                              0)); // Tworzymy nową tablicę o zadanych wymiarach i wypełniamy ją zerami
}

void Board::clear()
{
    cells.assign(height, vector<char>(width, 0));
    emit livingCellsCountUpdated(0);
}

void Board::nextGeneration()
{
    vector<vector<char>> newCells(height, vector<char>(width, 0));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (isAlive(i, j))
                newCells[i][j] = 1; // Komórka ożywa
            else
                newCells[i][j] = 0; // Komórka umiera
        }
    }

    cells = newCells;
}

int Board::countLivingCells() const
{
    int livingCellsCount = 0;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (getCell(i, j)) // Jeśli komórka jest żywa
                livingCellsCount++;
        }
    }

    return livingCellsCount;
}

bool Board::isAlive(const int x, const int y) const
{
    const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // Przesunięcia w osi x dla sąsiadów
    const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // Przesunięcia w osi y dla sąsiadów

    int alive = 0;

    for (int i = 0; i < 8; ++i) {
        int ni = x + dx[i];
        int nj = y + dy[i];

        // Sprawdź, czy współrzędne są w zakresie planszy
        if (ni >= 0 && ni < height && nj >= 0 && nj < width)
            alive += cells[ni][nj];
    }

    // ZASADY
    if (cells[x][y] == 1 && alive < 2)
        return false;
    if (cells[x][y] == 1 && (alive == 2 || alive == 3))
        return true;
    if (cells[x][y] == 1 && alive > 3)
        return false;
    if (cells[x][y] == 0 && alive == 3)
        return true;

    return false;
}

void Board::initializeBoardWithSeed(unsigned int seed)
{
    random_device rd;
    mt19937 gen(seed);                    // Użyj ziarna dla generatora liczb losowych
    uniform_int_distribution<> dis(0, 1); // Zakres losowania: 0 lub 1

    cells.resize(height, vector<char>(width, 0)); // Inicjalizacja tablicy dynamicznej

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j)
            cells[i][j] = dis(gen); // Użyj generatora liczb losowych z danym ziarnem
    }
}

void Board::setCells(std::vector<std::vector<char>> &newCells)
{
    if (newCells.size() == static_cast<size_t>(height)
        && newCells[0].size() == static_cast<size_t>(width)) {
        cells = newCells;
        emit livingCellsCountUpdated(countLivingCells());
    }
}

void Board::toggleCellState(int row, int col)
{
    if (row >= 0 && row < getHeight() && col >= 0
        && col < getWidth())                              // Sprawdź, czy indeksy są w zakresie
        cells[row][col] = (cells[row][col] == 1) ? 0 : 1; // Ożyw lub uśmierć komórkę
}
