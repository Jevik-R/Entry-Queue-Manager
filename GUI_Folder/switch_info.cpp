// #include "switch_info.h"
// #include "ui_switch_info.h"
// #include "switch_to_gate.h"
// #include<QMessageBox>
// SWITCH_INFO::SWITCH_INFO(QWidget *parent)
//     : QDialog(parent)

//     , ui(new Ui::SWITCH_INFO)
// {
//     ui->setupUi(this);
// }

// SWITCH_INFO::~SWITCH_INFO()
// {
//     delete ui;
// }

// void SWITCH_INFO::on_Yes_clicked()
// {

//     int val = ui->GateInfo->text().toInt();
//     SWITCH_TO_GATE gate_no ;
//     gate_no.setModal(true) ;
//     gate_no.exec() ;
//     hide() ;
// }

// void SWITCH_INFO::on_No_clicked()
// {
//     QMessageBox::warning(this, "warning" , "Sorry, ypu cannot switch queues!") ;
//     hide() ;
// }
