#include "quotesindexwindow.h"
#include "ui_quotesindexwindow.h"
#include <QDebug>
#include "dbmanager.h"
#include <QSqlQuery>
#include <limits>

QuotesIndexWindow::QuotesIndexWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuotesIndexWindow)
{
    ui->setupUi(this);

    // TODO: Write a method to call to do this, call it here
    DbManager db = DbManager();
    QSqlQuery results = db.allQuotes();

    ui->quotesIndexTableWidget->setColumnCount(2);
    int rowIndex = 0;
    while (results.next()) {
        ui->quotesIndexTableWidget->insertRow(rowIndex);

        // Quote
        QString quoteString = results.value(1).toString();
        QTableWidgetItem *quoteItem = new QTableWidgetItem(quoteString);
        ui->quotesIndexTableWidget->setItem(rowIndex, 0, quoteItem);

        // Quotee
        QString quoteeString = results.value(2).toString();
        QTableWidgetItem *quoteeItem = new QTableWidgetItem(quoteeString);
        ui->quotesIndexTableWidget->setItem(rowIndex, 1, quoteeItem);

        rowIndex++;
    }
    ui->quotesIndexTableWidget->resizeColumnsToContents();

    // TODO: Get the column height to resize to accomodate content size
    //       possible help: https://stackoverflow.com/a/25124763
    //
    //ui->quotesIndexTableWidget->setVisible(false);
    //QRect vporig = ui->quotesIndexTableWidget->viewport()->geometry();
    //QRect vpnew = vporig;
    //vpnew.setWidth(std::numeric_limits<int>::max());
    //ui->quotesIndexTableWidget->viewport()->setGeometry(vpnew);
    //ui->quotesIndexTableWidget->resizeColumnsToContents();
    //ui->quotesIndexTableWidget->resizeRowsToContents();
    //ui->quotesIndexTableWidget->viewport()->setGeometry(vporig);
    //ui->quotesIndexTableWidget->setVisible(true);
}

QuotesIndexWindow::~QuotesIndexWindow()
{
    delete ui;
}
