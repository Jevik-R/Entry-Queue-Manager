#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/png-clipart-queueing-theory-priority-queue-stack-abstract-data-type-others-miscellaneous-computer-network.png");
    ui->label_pic->setPixmap(pix.scaled(ui->label_pic->width(),ui->label_pic->height(),Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_stadium_authority_clicked()
{
    LOGIN login_stad;
    login_stad.setModal(true);
    login_stad.exec();

}

void MainWindow::on_pushButton_audience_clicked()
{
    hide();
    LOGIN login_aud;
    login_aud.setModal(true);
    login_aud.exec();
}

