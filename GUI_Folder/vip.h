#ifndef VIP_H
#define VIP_H

#include <QDialog>

namespace Ui {
class VIP;
}

class VIP : public QDialog
{
    Q_OBJECT

public:
    explicit VIP(QWidget *parent = nullptr);
    ~VIP();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::VIP *ui;
};

#endif // VIP_H
