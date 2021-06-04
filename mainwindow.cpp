#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "quotesindexwindow.h"
#include "dbmanager.h"

static const QString DB_PATH = "../CSC3220_DevTeam1.sqlite";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->nameSaveButton, SIGNAL(released()), this, SLOT(HandleNameSaveButtonPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::HandleNameSaveButtonPressed() {
    QString userName = ui->userNameInput->text();
    // TODO: Use existing DB connection
    DbManager db(DB_PATH);
    db.createUser(userName);
    close();
    QuotesIndexWindow *quotesIndexWindow = new QuotesIndexWindow();
    quotesIndexWindow->show();
}
