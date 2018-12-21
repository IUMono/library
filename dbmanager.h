#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QtSql>
#include <QMessageBox>


class DBManager
{


public:
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "connectionName");//    Второй параметр connectionName
    DBManager();
};

#endif // DBMANAGER_H
