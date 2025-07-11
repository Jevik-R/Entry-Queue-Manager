#ifndef INPUT_WINDOW_H
#define INPUT_WINDOW_H

#include <QDialog>

namespace Ui {
class INPUT_WINDOW;
}

class INPUT_WINDOW : public QDialog
{
    Q_OBJECT

public:
    explicit INPUT_WINDOW(QWidget *parent = nullptr);
    ~INPUT_WINDOW();

private slots:
    void on_pushButton_Done_clicked();

private:
    Ui::INPUT_WINDOW *ui;
};

#endif // INPUT_WINDOW_H
