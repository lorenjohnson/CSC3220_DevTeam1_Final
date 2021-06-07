#ifndef QUOTEFORMWINDOW_H
#define QUOTEFORMWINDOW_H

#include <QDialog>

namespace Ui {
class QuoteFormWindow;
}

class QuoteFormWindow : public QDialog
{
    Q_OBJECT

public:
    explicit QuoteFormWindow(QWidget *parent = nullptr);
    ~QuoteFormWindow();

private:
    Ui::QuoteFormWindow *ui;

private slots:
    void HandleSaveButtonPressed();
    void HandleCancelButtonPressed();
};


#endif // QUOTEFORMWINDOW_H
