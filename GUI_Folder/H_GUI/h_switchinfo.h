#ifndef H_SWITCHINFO_H
#define H_SWITCHINFO_H

#include <QDialog>

namespace Ui {
class H_SwitchInfo;
}

class H_SwitchInfo : public QDialog
{
    Q_OBJECT

public:
    explicit H_SwitchInfo(QWidget *parent = nullptr);
    ~H_SwitchInfo();

private slots:

    void on_Yes_clicked();

    void on_No_clicked();

private:
    Ui::H_SwitchInfo *ui;
};

#endif // H_SWITCHINFO_H
