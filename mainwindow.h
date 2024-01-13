#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QSpinBox>
#include "gameoflife.h"

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

private:
    Ui::MainWindow *ui;
    GameOfLife *game;
    QSpinBox *columnBox;
    QSpinBox *rowBox;

    const int initialWidth = 5;
    const int initialHeight = 5;

    void setupTable(int width, int height);
    void updateTable();

};
#endif // MAINWINDOW_H