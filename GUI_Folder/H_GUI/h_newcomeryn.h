#ifndef H_NEWCOMERYN_H
#define H_NEWCOMERYN_H

#include <QDialog>

namespace Ui {
class H_NewComerYN;
}

class H_NewComerYN : public QDialog
{
    Q_OBJECT

public:
    explicit H_NewComerYN(QWidget *parent = nullptr);
    ~H_NewComerYN();

private slots:

    void on_Yes_clicked();

    void on_No_clicked();

private:
    Ui::H_NewComerYN *ui;
};

#endif // H_NEWCOMERYN_H
