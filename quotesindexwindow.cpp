#include "quotesindexwindow.h"
#include "ui_quotesindexwindow.h"
#include "quoteformwindow.h"
#include <QDebug>
#include "dbmanager.h"
#include <QSqlQuery>
#include <limits>

QuotesIndexWindow::QuotesIndexWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuotesIndexWindow)
{
    ui->setupUi(this);

    connect(ui->newQuoteButton, SIGNAL(released()), this, SLOT(HandleNewQuoteButton()));

    // TODO: Write a method to all of the below, then call it here or some appropriate window load event?
    DbManager db = DbManager();

    QString userName = db.userName();
    ui->welcomeLabel->setText("Welcome " + userName);

    // Get all quotes and display in table
    QSqlQuery results = db.allQuotes();
    ui->quotesIndexTableWidget->setRowCount(10);

    int rowIndex = 0;
    while (results.next()) {
        ui->quotesIndexTableWidget->insertRow(rowIndex);

        // Quote
        QString quoteString = results.value(1).toString();
        QTableWidgetItem *quoteIndicator = new QTableWidgetItem("Quote: ");
        QTableWidgetItem *quoteItem = new QTableWidgetItem(quoteString);
        ui->quotesIndexTableWidget->setItem(rowIndex, 0, quoteIndicator);
        ui->quotesIndexTableWidget->setItem(rowIndex, 1, quoteItem);
        ui->quotesIndexTableWidget->resizeRowsToContents();
        rowIndex++;

        // Quotee
        QString quoteeString = results.value(2).toString();
        QTableWidgetItem *authorIndicator = new QTableWidgetItem("Quotee: ");
        QTableWidgetItem *quoteeItem = new QTableWidgetItem(quoteeString);
        ui->quotesIndexTableWidget->setItem(rowIndex, 0, authorIndicator);
        ui->quotesIndexTableWidget->setItem(rowIndex, 1, quoteeItem);
        rowIndex++;
    }
    ui->quotesIndexTableWidget->resizeColumnsToContents();

    // TODO: Get the column height to resize to accomodate content size
    //       possible help: https://stackoverflow.com/a/25124763
    // ui->quotesIndexTableWidget->horizontalHeader()->setResizeMode(8, QHeaderView::Fixed);
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


void QuotesIndexWindow::HandleNewQuoteButton() {
    this->close();
    QuoteFormWindow *quoteFormWindow = new QuoteFormWindow();
    quoteFormWindow->show();
}
