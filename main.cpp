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
        // TODO: Remove once we have a New Quote form
        db.createQuote("A couple people seem to be reticent about the term ‘study,’ but is there a way to be in the undercommons that isn’t intellectual? Is there a way of being intellectual that isn’t social? When I think about the way we were using the term ‘study,’ I think we were committed to the idea that study is what you do with other people. It’s talking and walking around with other people, working, dancing, suffering, some irreducible convergence of all three, held under the name of speculative practice. The notion of a rehearsal – being in a kind of workshop, playing in a band, in a jam session, or old men sitting on a porch, or people working together in a factory – there are these various modes of activity. The point of calling it ‘study’ is to mark that the incessant and irreversible intellectuality of these activities was already there. These activities aren’t ennobled by the fact that we now say, ‘oh, if you did these things in a certain way, you could be said to be have been studying.’ To do these things is to be involved in a kind of common intellectual practice. What’s important is to recognize that that has been the case – because that recognition allows you to access a whole, varied, alternative history of thought", "Fred Moten");
    }
    else
    {
        qDebug() << "Database is not open!";
    }

    MainWindow w;
    w.show();

    return a.exec();
}
