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
    connect(ui->saveButton, SIGNAL(released()), this, SLOT(HandleSaveButtonPressed()));
    connect(ui->cancelButton, SIGNAL(released()), this, SLOT(HandleCancelButtonPressed()));
}

QuoteFormWindow::~QuoteFormWindow()
{
    delete ui;
}

void QuoteFormWindow::HandleSaveButtonPressed() {
    QString quoteString = ui->quoteText->toPlainText();
    QString quoteeString = ui->quoteeText->text();

    if (!quoteString.isEmpty() && !quoteeString.isEmpty()) {
        DbManager db = DbManager();
        db.createQuote(quoteString, quoteeString);
        QDialog::accept();
        QuotesIndexWindow *quotesIndexWindow = new QuotesIndexWindow();
        quotesIndexWindow->show();
    }
}

void QuoteFormWindow::HandleCancelButtonPressed() {
    QDialog::reject();
    QuotesIndexWindow *quotesIndexWindow = new QuotesIndexWindow();
    quotesIndexWindow->show();
}
