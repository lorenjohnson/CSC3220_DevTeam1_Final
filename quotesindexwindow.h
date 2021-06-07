#ifndef QUOTESINDEXWINDOW_H
#define QUOTESINDEXWINDOW_H

#include <QWidget>

namespace Ui {
class QuotesIndexWindow;
}

class QuotesIndexWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QuotesIndexWindow(QWidget *parent = nullptr);
    ~QuotesIndexWindow();

private:
    Ui::QuotesIndexWindow *ui;

private slots:
    void HandleNewQuoteButton();
};
#endif // QUOTESINDEXWINDOW_H
