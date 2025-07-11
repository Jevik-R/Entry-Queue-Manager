#include "h_switchinfo.h"
#include "ui_h_switchinfo.h"
#include "h_switchtogate.h"
#include "QMessageBox"

H_SwitchInfo::H_SwitchInfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::H_SwitchInfo)
{
    ui->setupUi(this);
}

H_SwitchInfo::~H_SwitchInfo()
{
    delete ui;
}

void H_SwitchInfo::on_Yes_clicked()
{
    int val = ui->GateInfo->text().toInt();
    H_SwitchToGate gate_no ;
    gate_no.setModal(true) ;
    gate_no.exec() ;
    hide() ;
}

void H_SwitchInfo::on_No_clicked()
{
    QMessageBox::warning(this, "warning" , "Sorry, ypu cannot switch queues!") ;
    hide() ;
}

