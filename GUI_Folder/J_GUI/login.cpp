#include "login.h"
#include <QMessageBox>
#include "ui_login.h"
#include <QPixmap>

LOGIN::LOGIN(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LOGIN)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/login.jpg");
    ui->label_pic->setPixmap(pix.scaled(ui->label_pic->width(),ui->label_pic->height(),Qt::KeepAspectRatio));
}

LOGIN::~LOGIN()

{
    delete ui;
}

void LOGIN::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (username == "audience" && password == "1234") {
        QMessageBox::information(this, "LoginIn", "Loged in Successfull");
        hide();

        //ADD CODE FOR NEXT PAGE FOR AUDIENCE

    }
    else if(username == "stadium_authority" && password == "1234"){
        QMessageBox::information(this, "LoginIn", "Loged in Successfull");
        hide();
        //STADIUM CODE

    }
    else
        QMessageBox::warning(this, "Login", "Username and Password incorrect");
}
