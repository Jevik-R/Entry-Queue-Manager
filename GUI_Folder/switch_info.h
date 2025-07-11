#ifndef SWITCH_INFO_H
#define SWITCH_INFO_H

#include <QDialog>

namespace Ui {
class SWITCH_INFO;
}

class SWITCH_INFO : public QDialog
{
    Q_OBJECT

public:
    explicit SWITCH_INFO(QWidget *parent = nullptr);
    ~SWITCH_INFO();

private slots:
    void on_Yes_clicked();

    void on_No_clicked();

private:
    Ui::SWITCH_INFO *ui;
};

#endif // SWITCH_INFO_H
