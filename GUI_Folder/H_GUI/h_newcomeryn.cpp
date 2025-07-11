#include "h_newcomeryn.h"
#include "ui_h_newcomeryn.h"
#include "h_famgroupyn.h"
#include "h_switchinfo.h"

H_NewComerYN::H_NewComerYN(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::H_NewComerYN)
{
    ui->setupUi(this);
    // connect(ui->Yes, &QPushButton::clicked, this, &H_NewComerYN::onYesClicked);
    // connect(ui->No, &QPushButton::clicked, this, &H_NewComerYN::onNoClicked);
}

H_NewComerYN::~H_NewComerYN()
{
    delete ui;
}
void H_NewComerYN::on_Yes_clicked()
{
    H_FamGroupYN yn ;
    yn.setModal(true) ;
    yn.exec() ;
    hide() ;
}

void H_NewComerYN::on_No_clicked()
{
    H_SwitchInfo info;
    info.setModal(true);
    info.exec();
    hide() ;
}
