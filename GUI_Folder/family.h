#ifndef FAMILY_H
#define FAMILY_H

#include <QDialog>

namespace Ui {
class FAMILY;
}

class FAMILY : public QDialog
{
    Q_OBJECT

public:
    explicit FAMILY(QWidget *parent = nullptr);
    ~FAMILY();

private slots:
    void on_Yes_clicked();

    void on_No_clicked();

private:
    Ui::FAMILY *ui;
};

#endif // FAMILY_H
