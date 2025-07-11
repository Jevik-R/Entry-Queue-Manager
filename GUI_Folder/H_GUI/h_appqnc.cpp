#include "h_appqnc.h"
#include "ui_h_appqnc.h"

H_appQNC::H_appQNC(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::H_appQNC)
{
    ui->setupUi(this);
}

H_appQNC::~H_appQNC()
{
    delete ui;
}

void H_appQNC::on_pushButton_clicked()
{
    hide() ; // Done button
}

