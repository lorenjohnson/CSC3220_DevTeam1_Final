#include "quotesindexwindow.h"
#include "ui_quotesindexwindow.h"

QuotesIndexWindow::QuotesIndexWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuotesIndexWindow)
{
    ui->setupUi(this);
}

QuotesIndexWindow::~QuotesIndexWindow()
{
    delete ui;
}

// QListWidgetItem *item = ui->quotesIndexWindow->currentItem();
// setData(<array of rows>, an ID for the dataset?)
// QListWidgetItem *item = ui->quotesIndexWindow->setData([], ID);
// QListWidgetItem *item = ui->quotesIndexWindow->currentItem();

