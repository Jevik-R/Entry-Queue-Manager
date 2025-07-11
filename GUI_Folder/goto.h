#ifndef GOTO_H
#define GOTO_H

#include <QDialog>

namespace Ui {
class GOTO;
}

class GOTO : public QDialog
{
    Q_OBJECT

public:
    explicit GOTO(QWidget *parent = nullptr);
    ~GOTO();
    void updateNumber(int gateNoValue, int waitTimeValue);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::GOTO *ui;
};

#endif // GOTO_H
