#include <dbmanager.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DbManager::DbManager()
{
    m_db = QSqlDatabase::database();

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

bool DbManager::createUsersTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare(
        "CREATE TABLE users ( \
            id              INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, \
            name            TEXT NOT NULL \
        );"
    );

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'users': one might already exist.";
        success = false;
    }


    return success;
}

bool DbManager::createQuotesTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare(
        "CREATE TABLE quotes ( \
            id              INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, \
            content         TEXT NOT NULL, \
            quotee_name     TEXT NOT NULL \
        );"
    );

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'quotes': one might already exist.";
        success = false;
    }

    return success;
}

bool DbManager::createUser(const QString& name)
{
    bool success = false;

    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;

        queryAdd.prepare("INSERT INTO users(name) VALUES(:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add user failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add user failed: quote content cannot be empty";
    }

    return success;
}

bool DbManager::createQuote(const QString& quoteContent, const QString& quoteeName)
{
    bool success = false;

    if (!quoteContent.isEmpty())
    {
        QSqlQuery queryAdd;

        queryAdd.prepare("INSERT INTO quotes(content, quotee_name) VALUES(:quoteContent, :quoteeName)");
        queryAdd.bindValue(":quoteContent", quoteContent);
        queryAdd.bindValue(":quoteeName", quoteeName);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add quote failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add quote failed: quote content cannot be empty";
    }

    return success;
}

bool DbManager::deleteQuote(const int quoteId)
{
    bool success = false;

    QSqlQuery queryDelete;
    queryDelete.prepare("DELETE FROM quotes WHERE id = (:quoteId)");
    queryDelete.bindValue(":quoteId", quoteId);
    success = queryDelete.exec();

    if(!success)
    {
        qDebug() << "remove person failed: " << queryDelete.lastError();
    }

    return success;
}

QString DbManager::userName() {
    QSqlQuery queryUser;
    queryUser.prepare("SELECT * FROM users");
    queryUser.exec();
    queryUser.next();

    QString userName = queryUser.value(1).toString();

    return userName;
}

QSqlQuery DbManager::allQuotes() {
    QSqlQuery queryQuotes;
    queryQuotes.prepare("SELECT * FROM quotes ORDER BY id DESC");
    queryQuotes.exec();

    return queryQuotes;
}

//bool DbManager::addPerson(const QString& name)
//{
//    bool success = false;

//    if (!name.isEmpty())
//    {
//        QSqlQuery queryAdd;
//        queryAdd.prepare("INSERT INTO people (name) VALUES (:name)");
//        queryAdd.bindValue(":name", name);

//        if(queryAdd.exec())
//        {
//            success = true;
//        }
//        else
//        {
//            qDebug() << "add person failed: " << queryAdd.lastError();
//        }
//    }
//    else
//    {
//        qDebug() << "add person failed: name cannot be empty";
//    }

//    return success;
//}


//void DbManager::printAllPersons() const
//{
//    qDebug() << "Persons in db:";
//    QSqlQuery query("SELECT * FROM people");
//    int idName = query.record().indexOf("name");
//    while (query.next())
//    {
//        QString name = query.value(idName).toString();
//        qDebug() << "===" << name;
//    }
//}

//bool DbManager::personExists(const QString& name) const
//{
//    bool exists = false;

//    QSqlQuery checkQuery;
//    checkQuery.prepare("SELECT name FROM people WHERE name = (:name)");
//    checkQuery.bindValue(":name", name);

//    if (checkQuery.exec())
//    {
//        if (checkQuery.next())
//        {
//            exists = true;
//        }
//    }
//    else
//    {
//        qDebug() << "person exists failed: " << checkQuery.lastError();
//    }

//    return exists;
//}

//bool DbManager::removeAllPersons()
//{
//    bool success = false;

//    QSqlQuery removeQuery;
//    removeQuery.prepare("DELETE FROM people");

//    if (removeQuery.exec())
//    {
//        success = true;
//    }
//    else
//    {
//        qDebug() << "remove all persons failed: " << removeQuery.lastError();
//    }

//    return success;
//}
