#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QSpinBox>
#include "gameoflife.h"
#include <QLCDNumber>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_stepButton_clicked();
    void on_rowBox_valueChanged(int newWidth);
    void on_columnBox_valueChanged(int newHeight);
    void on_setSeedBox_valueChanged(int seed);
    void on_randomButton_clicked();
    void on_clearButton_clicked();
    void on_startButton_clicked();


    void on_pauseResumeButton_clicked();


private:
    Ui::MainWindow *ui;
    GameOfLife *game;
    QSpinBox *columnBox;
    QSpinBox *rowBox;
    QLCDNumber *speedLCD;

    const int initialWidth = 10;
    const int initialHeight = 10;

    void setupTable(int width, int height);
    void updateTable();

};
#endif // MAINWINDOW_H
