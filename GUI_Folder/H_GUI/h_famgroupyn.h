#ifndef H_FAMGROUPYN_H
#define H_FAMGROUPYN_H

#include <QDialog>

namespace Ui {
class H_FamGroupYN;
}

class H_FamGroupYN : public QDialog
{
    Q_OBJECT

public:
    explicit H_FamGroupYN(QWidget *parent = nullptr);
    ~H_FamGroupYN();

private slots:
    void on_Yes_clicked();

    void on_No_clicked();

private:
    Ui::H_FamGroupYN *ui;
};

#endif // H_FAMGROUPYN_H
