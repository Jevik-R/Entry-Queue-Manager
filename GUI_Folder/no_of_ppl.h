#ifndef NO_OF_PPL_H
#define NO_OF_PPL_H

#include <QDialog>

namespace Ui {
class NO_OF_PPL;
}

class NO_OF_PPL : public QDialog
{
    Q_OBJECT

public:
    explicit NO_OF_PPL(QWidget *parent = nullptr);
    ~NO_OF_PPL();

private slots:
    void on_Done_clicked();

private:
    Ui::NO_OF_PPL *ui;
};

#endif // NO_OF_PPL_H
