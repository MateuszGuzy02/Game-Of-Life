#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QColor>
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QLCDNumber>
#include <QMainWindow>
#include <QMouseEvent>
#include <QSpinBox>
#include <QTableWidgetItem>
#include <QTextStream>
#include "gameoflife.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void cellClicked(int row, int col);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rowBox_valueChanged(int newWidth);
    void on_columnBox_valueChanged(int newHeight);
    void on_setSeedBox_valueChanged(int seed);
    void on_randomButton_clicked();
    void on_clearButton_clicked();
    void updateLivingCellsLCD(int count);
    void updateTotalStepsLCD(int steps);
    void on_stepButton_clicked();
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void on_resumeButton_clicked();
    void on_stopButton_clicked();
    void saveToFile();
    void openFromFile();
    void on_actionColorLivingCells_triggered();
    void on_actionColor_of_dead_cells_triggered();
    void onBoardSizeChanged(int height, int width);
    void updateTotalSteps(int steps);
    void updateIntervalLCD(int interval);
    void on_speedDial_sliderReleased();

private:
    Ui::MainWindow *ui;
    GameOfLife *game;
    QSpinBox *columnBox;
    QSpinBox *rowBox;
    QLCDNumber *speedLCD;
    QAction *actionSave;
    QAction *actionOpen;

    const int initialWidth = 10;
    const int initialHeight = 10;

    void setupTable(int width, int height);
    void updateTable();

protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
