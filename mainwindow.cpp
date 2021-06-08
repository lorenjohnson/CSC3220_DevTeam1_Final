#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "quotesindexwindow.h"
#include "dbmanager.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
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
    if (!userName.isEmpty()) {
        DbManager db = DbManager();
        db.createUser(userName);
        this->close();
        QuotesIndexWindow *quotesIndexWindow = new QuotesIndexWindow();
        quotesIndexWindow->show();
    }
}
