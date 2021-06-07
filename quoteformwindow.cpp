#include "quoteformwindow.h"
#include "ui_quoteformwindow.h"
#include "quotesindexwindow.h"
#include <dbmanager.h>
#include <QDebug>

QuoteFormWindow::QuoteFormWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuoteFormWindow)
{
    ui->setupUi(this);
    connect(ui->saveOrCancel, SIGNAL(accepted()), this, SLOT(HandleSaveButtonPressed()));
    connect(ui->saveOrCancel, SIGNAL(rejected()), this, SLOT(HandleCancelButtonPressed()));
}

QuoteFormWindow::~QuoteFormWindow()
{
    delete ui;
}

void QuoteFormWindow::HandleSaveButtonPressed() {
    QString quoteString = ui->quoteText->toPlainText();
    QString quoteeString = ui->quoteeText->text();
    DbManager db = DbManager();
    db.createQuote(quoteString, quoteeString);
    // TODO: Check for empty on both fields
    QuotesIndexWindow *quotesIndexWindow = new QuotesIndexWindow();
    quotesIndexWindow->show();
}

void QuoteFormWindow::HandleCancelButtonPressed() {
    qDebug() << "pressed cancel button";
    QuotesIndexWindow *quotesIndexWindow = new QuotesIndexWindow();
    quotesIndexWindow->show();
}
