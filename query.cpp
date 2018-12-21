#include "query.h"
#include <QtDebug>

query::query()
{
    nameBook = "";
    author = "";
    genre = "";
    mood = "";
    keywords = "";
    film = false;
}

void query::generateQuery()
{
    if (!dbManager.db.open())
    {
        QMessageBox error;
        error.setWindowTitle("Ошибка");
        error.setText("Не удалось подключиться к базе данных");
        error.exec();
    }
//    SELECT author.sur_name, author.name, middle_name, title
//    FROM books join author on books.id_autor = author.id
//    WHERE author.sur_name = 'Достоевский' and author.name = 'Фёдор' and middle_name = 'Михайлович';

//    QString stringQuery = "SELECT author.sur_name, author.name, middle_name, title FROM books join author on books.id_autor = author.id WHERE ";
    QString stringQuery = "SELECT func(author.sur_name, author.name, author.middle_name) FROM author WHERE ";
    bool theAuthorIsEntered = false;

    if (author.size() != 0)
    {
        theAuthorIsEntered = true;
        QStringList stringsListName = author.split(" ");
        if (stringsListName.size() >= 2)
        {
//            stringQuery.append("author.sur_name = '" + stringsListName[0] + "' AND author.name = '" + stringsListName[1] + "'");
            stringQuery.append("sur_name = \'" + stringsListName[0] + "\'");
        }
//        if (stringsListName.size() == 3)
//        {
//            stringQuery.append(" AND middle_name = '" + stringsListName[2] + "'");
//        }
    }

    if (nameBook.size() != 0)
    {
        if(theAuthorIsEntered)
        {
            stringQuery.append("AND ");
        }
        stringQuery.append("title = " + nameBook);
    }

//    if (genre.size() != 0)
//    {
//        //
//        stringQuery.append("");
//    }

//    if (keywords.size() != 0) {

//    }

//    if (film)
//    {

//    }

    QSqlQuery query = dbManager.db.exec(stringQuery);
//    qDebug()<<dbManager.db.lastError().text();
//    qDebug()<<dbManager.db.lastError().driverText();

//    if (dbManager.db.exec(stringQuery))
//    {
    if(query.first()){
//        while (query.next()) {
            cell cell;
            cell.author = query.value(0).toString(); //+ query.value(1).toString() + query.value(2).toString();
//            cell.nameBook = query.value(3).toString();
            cells.append(cell);
//        }
    }
    else {
        qDebug()<<dbManager.db.lastError().text();
        qDebug()<<dbManager.db.lastError().driverText();


//        QMessageBox error;
//        error.setWindowTitle("Ошибка");
//        error.setText("Не удалось выполнить запрос");
//        error.exec();
    }
}


