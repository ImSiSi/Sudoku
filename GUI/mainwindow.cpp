#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Solution.h"
#include <QTableWidgetItem>
#include "SudokuDelegate.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setItemDelegate(new SudokuDelegate(this));

    // 設定 tableWidget 固定大小
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->resize(800, 600);
    // 設置只能輸入一個字元
    for(int r=0; r<9; ++r){
        for(int c=0; c<9; ++c){
            ui->tableWidget->setItem(r, c, new QTableWidgetItem(""));
            ui->tableWidget->item(r, c)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadBoardFromTable()
{
    board.clear();
    for(int i=0; i<9; ++i){
        std::vector<char> row;
        for(int j=0; j<9; ++j){
            QTableWidgetItem* item = ui->tableWidget->item(i, j);
            if (!item || item->text().isEmpty() || item->text() == "."){
                row.push_back('.');
            } else {
                QString text = item->text();
                if(text.length() == 1 && text[0].isDigit()){
                    row.push_back(text[0].toLatin1());
                } else {
                    row.push_back('.');
                }
            }
        }
        board.push_back(row);
    }
}

void MainWindow::updateTableFromBoard()
{
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            char val = board[i][j];
            ui->tableWidget->item(i,j)->setText(val == '.' ? "" : QString(val));
        }
    }
}

void MainWindow::on_solveButton_clicked()
{
    loadBoardFromTable();

    Solution solver;
    std::vector<std::vector<char>> originalBoard = board;

    if (!solver.solveSudoku(board)) {
        QMessageBox::warning(this, "解題失敗", "此數獨無解！");
        return;
    }

    updateTableFromBoard();
}

void MainWindow::on_clearButton_clicked()
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            ui->tableWidget->item(i, j)->setText("");
        }
    }

    board = std::vector<std::vector<char>>(9, std::vector<char>(9, '.'));
}

