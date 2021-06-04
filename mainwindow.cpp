#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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
    qDebug() << "Save button clicked";
    //    // Find out which button was pressed
    //    QPushButton *button = (QPushButton*)sender();
    //    // Get the value of the button pressed
    //    QString butVal = button->text();
    //    // Get the current display value
    //    QString displayVal = ui->Display->text();
    //    // Process the button press (one number at a time)
    //    if ((displayVal.toDouble() == 0.0 || displayVal.toDouble() == 0)) {
    //        ui->Display->setText(butVal); // This is the first number pressed, just display it
    //    } else {
    //        QString newVal = displayVal + butVal;  // Concat the new number on to the old
    //        double dblNewVal = newVal.toDouble();
    //        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
    //    }
}
