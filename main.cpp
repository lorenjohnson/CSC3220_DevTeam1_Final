#include "mainwindow.h"
#include <QApplication>
#include <dbmanager.h>
#include <QDebug>

static const QString DB_PATH = "../CSC3220_DevTeam1.sqlite";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DbManager db(DB_PATH);

    if (db.isOpen())
    {
        db.createUsersTable();
        db.createQuotesTable();
        db.createUser("Loren Johnson");
        db.createQuote("For score and seven years ago...", "Abraham Lincoln");
    }
    else
    {
        qDebug() << "Database is not open!";
    }

    MainWindow w;
    w.show();

    return a.exec();
}
