#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

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
    void on_solveButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<char>> board;
    void loadBoardFromTable();
    void updateTableFromBoard();
};

#endif // MAINWINDOW_H
