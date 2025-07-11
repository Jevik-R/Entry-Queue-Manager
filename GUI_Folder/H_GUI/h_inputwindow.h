#ifndef H_INPUTWINDOW_H
#define H_INPUTWINDOW_H

#include <QDialog>

namespace Ui {
class H_InputWindow;
}

class H_InputWindow : public QDialog
{
    Q_OBJECT

public:
    explicit H_InputWindow(QWidget *parent = nullptr);
    ~H_InputWindow();

private slots:
    void on_pushButton_Done_clicked();

private:
    Ui::H_InputWindow *ui;
};

#endif // H_INPUTWINDOW_H
