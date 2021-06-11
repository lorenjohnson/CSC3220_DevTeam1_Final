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
    ui->quotesIndexTableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->quotesIndexTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    int rowIndex = 0;
    while (results.next()) {
        ui->quotesIndexTableWidget->insertRow(rowIndex);

        // Quote
        QString quoteString = "\"" + results.value(1).toString() + "\"";
        QTableWidgetItem *quoteItem = new QTableWidgetItem(quoteString);
        quoteItem->setTextAlignment(Qt::AlignTop);
        quoteItem->setSizeHint(QSize(500,100));
        quoteItem->setFont(QFont("Times", 16, QFont::Normal));
        ui->quotesIndexTableWidget->setItem(rowIndex, 0, quoteItem);

        // Quotee
        QString quoteeString = "- " + results.value(2).toString();
        QTableWidgetItem *quoteeItem = new QTableWidgetItem(quoteeString);
        quoteeItem->setFont(QFont("Times", 16, QFont::Bold));
        quoteeItem->setTextAlignment(Qt::AlignTop | Qt::AlignRight);
        ui->quotesIndexTableWidget->setItem(rowIndex, 1, quoteeItem);
        rowIndex++;
    }
    ui->quotesIndexTableWidget->resizeRowsToContents();
    ui->quotesIndexTableWidget->resizeColumnsToContents();

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
