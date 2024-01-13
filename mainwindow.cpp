#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , game(5, 5)
{
    ui->setupUi(this);
    game.setRandomSeed(18);

    setupTable();  // Inicjalizacja tabeli

    connect(ui->stepButton, &QPushButton::clicked, &game, &GameOfLife::displayBoard);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTable() {
    ui->gameTable->setRowCount(game.getBoard().getHeight());
    ui->gameTable->setColumnCount(game.getBoard().getWidth());

    // Ukryj numerowanie wierszy i kolumn
    ui->gameTable->verticalHeader()->setVisible(false);
    ui->gameTable->horizontalHeader()->setVisible(false);

    // Inicjalizacja komórek tabeli
    for (int i = 0; i < game.getBoard().getHeight(); ++i) {
        for (int j = 0; j < game.getBoard().getWidth(); ++j) {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);  // Blokada edycji komórek
            ui->gameTable->setItem(i, j, item);
        }
    }

    updateTable();  // Aktualizacja zawartości tabeli po inicjalizacji
}

void MainWindow::updateTable() {
    game.getBoard().printBoard(ui->gameTable);
    ui->gameTable->viewport()->update();
}

void MainWindow::on_stepButton_clicked()
{
    game.displayBoard();
    updateTable();
}

