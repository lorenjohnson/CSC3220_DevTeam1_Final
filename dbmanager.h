#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

/**
 * \class DbManager
 *
 * \brief SQL Database Manager class
 *
 * DbManager sets up the connection with SQL database
 * and performs some basics queries. The class requires
 * existing SQL database. You can create it with sqlite:
 * 1. $ sqlite3 people.db
 * 2. sqilte> CREATE TABLE people(ids integer primary key, name text);
 * 3. sqlite> .quit
 */
class DbManager
{
public:
    /**
     * @brief Constructor
     *
     * Constructor sets up connection with db and opens it
     * @param path - absolute path to db file
     */
    DbManager(const QString& path);

    /**
     * @brief Constructor
     *
     * Constructor gets existing connection to db
     */
    DbManager();

    /**
     * @brief Destructor
     *
     * Close the db connection
     */
    ~DbManager();

    bool isOpen() const;

    /**
     * @brief Creates new 'users' table if it doesn't already exist
     * @return true - table created successfully, false - table not created
     */
    bool createUsersTable();

    /**
     * @brief Creates new 'quotes' table if it doesn't already exist
     * @return true - table created successfully, false - table not created
     */
    bool createQuotesTable();

    /**
     * @brief Add quote data to db (should assume current user)
     * @param quoteContent - the quote
     * @param quoteeName - the quotee
     * @return true - quote added successfully, false - quote not added
     */
    bool createQuote(const QString& quoteContent, const QString& quoteeName);

    /**
     * @brief Add user data to db
     * @param name - name of user to add
     * @return true - user added successfully, false - user not added
     */
    bool createUser(const QString& name);

    /**
     * @brief Remove person data from db
     * @param name - name of person to remove.
     * @return true - person removed successfully, false - person not removed
     */
    bool deleteQuote(const int quoteId);

    /**
     * @brief Returns user's name if a user has already been created, empty if it doesn't
     */
    QString userName();

    /**
     * @brief Return all quotes from db
     */
    QSqlQuery allQuotes();


//    /**
//     * @brief Check if person of name "name" exists in db
//     * @param name - name of person to check.
//     * @return true - person exists, false - person does not exist
//     */
//    bool personExists(const QString& name) const;

//    /**
//     * @brief Print names of all persons in db
//     */
//    void printAllPersons() const;

//    /**
//     * @brief Remove all persons from db
//     * @return true - all persons removed successfully, false - not removed
//     */
//    bool removeAllPersons();

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
