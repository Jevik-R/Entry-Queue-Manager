#ifndef H_APPQNC_H
#define H_APPQNC_H

#include <QDialog>

namespace Ui {
class H_appQNC;
}

class H_appQNC : public QDialog
{
    Q_OBJECT

public:
    explicit H_appQNC(QWidget *parent = nullptr);
    ~H_appQNC();

private slots:
    void on_pushButton_clicked();

private:
    Ui::H_appQNC *ui;
};

#endif // H_APPQNC_H
