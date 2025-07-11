#ifndef Q_STATUS_H
#define Q_STATUS_H

#include <QDialog>

namespace Ui {
class Q_STATUS;
}

class Q_STATUS : public QDialog
{
    Q_OBJECT

public:
    explicit Q_STATUS(QWidget *parent = nullptr);
    ~Q_STATUS();
    void appendSentence(const QString& sentence) ;
    void onSentenceReceived(const QString& sentence) ;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Q_STATUS *ui;
};

#endif // Q_STATUS_H
