#include "mainwindow.h"
#include <QApplication>
#include <dbmanager.h>
#include <QDebug>
#include "quotesindexwindow.h"

static const QString DB_PATH = "QuotesManager.sqlite";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DbManager db = DbManager(DB_PATH);

    if (db.isOpen())
    {
        db.createUsersTable();
        db.createQuotesTable();
    }
    else
    {
        qDebug() << "Database is not open!";
    }

    if (!db.userName().isEmpty())
    {
        QuotesIndexWindow *quotesIndexWindow = new QuotesIndexWindow();
        quotesIndexWindow->show();
    }
    else
    {
        MainWindow *welcomeWindow = new MainWindow();
        welcomeWindow->show();
    }

    return a.exec();
}
