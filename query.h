#ifndef QUERY_H
#define QUERY_H
#include <QString>
#include <QtSql>
#include <QMessageBox>
#include <QVector>

#include "dbmanager.h"

struct cell
{
    QString nameBook;
    QString author;
    bool film = false;
};

class query
{
    DBManager dbManager;
public:
    query();
    QString nameBook;
    QString author;
    QString genre;
    QString mood;
    QString keywords;
    bool film;
    QVector<cell> cells;

    void generateQuery();
private:

};

#endif // QUERY_H
