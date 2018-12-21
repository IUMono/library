#include "mainwindow.h"
#include <QApplication>
//#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //qDebug() << QSqlDatabase::drivers();
    return a.exec();
}
