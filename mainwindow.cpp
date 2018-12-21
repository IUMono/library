#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QtCore/QCoreApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton{background:#6E6F71;}");
    ui->authorlineEdit->setStyleSheet("QLineEdit{background:#6E6F71;}");
    ui->nameBooklineEdit->setStyleSheet("QLineEdit{background:#6E6F71;}");
    ui->keywordsLineEdit->setStyleSheet("QLineEdit{background:#6E6F71;}");
    ui->genresComboBox->setStyleSheet("QComboBox{background:#6E6F71;}");
    ui->moodsComboBox->setStyleSheet("QComboBox{background:#6E6F71;}");
    ui->tableWidget->setStyleSheet("QTableWidget{background:#6E6F71;}");
    addValuesForComboBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addValuesForComboBox()
{
    QList<QString> stringsListGenres;
    stringsListGenres.append("Роман");
    stringsListGenres.append("Роман в стихах");
    stringsListGenres.append("Поэма");
    stringsListGenres.append("Стихотворение");
    stringsListGenres.append("Повесть");
    stringsListGenres.append("Книги по психологии");

    ui->genresComboBox->addItems(stringsListGenres);

    QList<QString> stringsListMoods;
    stringsListMoods.append("Радость");
    stringsListMoods.append("Спокойствие");
    stringsListMoods.append("Грусть");
    stringsListMoods.append("Мечтательность");
    stringsListMoods.append("Меланхолия");
    stringsListMoods.append("Влюбленность");
    stringsListMoods.append("Легкость");
    stringsListMoods.append("Под одеялком");
    stringsListMoods.append("Ярость");
    stringsListMoods.append("В путешествие");
    stringsListMoods.append("Задумчивость");
    stringsListMoods.append("Усталость");
    stringsListMoods.append("Противостояние");
    stringsListMoods.append("Депрессия");

    ui->moodsComboBox->addItems(stringsListMoods);
}

void MainWindow::on_pushButton_clicked()
{
    query.nameBook = ui->nameBooklineEdit->text();
    query.author = ui->authorlineEdit->text();
    query.genre = ui->genresComboBox->currentText();
    query.mood = ui->moodsComboBox->currentText();
    query.keywords = ui->keywordsLineEdit->text();
    query.film = ui->filmRadioButton->isDown();
    query.generateQuery();
    generateTable();
}

void MainWindow::generateTable()
{
    ui->tableWidget->setRowCount(query.cells.size());

    for(int i = 0; i<query.cells.size(); i++)
    {
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(query.cells.at(i).author);
//    item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, item);
        // и так до последнего столбца
    }
}

//по названию
void MainWindow::showTable()
{
    ui->tableWidget->setRowCount(1);
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(query.cells.at(0).author);
//    item->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, item);
}
