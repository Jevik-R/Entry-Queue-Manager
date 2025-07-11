#ifndef SWITCH_TO_GATE_H
#define SWITCH_TO_GATE_H

#include <QDialog>

namespace Ui {
class SWITCH_TO_GATE;
}

class SWITCH_TO_GATE : public QDialog
{
    Q_OBJECT

public:
    explicit SWITCH_TO_GATE(QWidget *parent = nullptr);
    ~SWITCH_TO_GATE();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SWITCH_TO_GATE *ui;
};

#endif // SWITCH_TO_GATE_H
