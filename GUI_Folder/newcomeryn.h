#ifndef NEWCOMERYN_H
#define NEWCOMERYN_H

#include <QDialog>

namespace Ui {
class NEWCOMERYN;
}

class NEWCOMERYN : public QDialog
{
    Q_OBJECT

public:
    explicit NEWCOMERYN(QWidget *parent = nullptr);
    ~NEWCOMERYN();

private slots:
    void on_Yes_clicked();

    void on_No_clicked();

private:
    Ui::NEWCOMERYN *ui;
};

#endif // NEWCOMERYN_H
