#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "query.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    query query;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addValuesForComboBox();
    void generateTable();
    void showTable();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
