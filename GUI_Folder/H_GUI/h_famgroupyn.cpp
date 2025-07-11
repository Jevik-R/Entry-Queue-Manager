#include "h_famgroupyn.h"
#include "ui_h_famgroupyn.h"
#include "h_appqnc.h"
#include <QPixmap>

H_FamGroupYN::H_FamGroupYN(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::H_FamGroupYN)
{
    ui->setupUi(this);
    QPixmap pix("C:/One Drive stuff/Desktop/Data/Pictures/Saved Pictures/Capstone images/fam.png") ;
    QPixmap pixx("C:/One Drive stuff/Desktop/Data/Pictures/Saved Pictures/Capstone images/Single.png") ;
    ui->label_pic->setPixmap(pix.scaled(ui->label_pic->width(),ui->label_pic->height(),Qt::KeepAspectRatio));
    ui->label_pic2->setPixmap(pixx.scaled(ui->label_pic2->width(),ui->label_pic2->height(),Qt::KeepAspectRatio));
}
H_FamGroupYN::~H_FamGroupYN()
{
    delete ui;
}



void H_FamGroupYN::on_Yes_clicked()
{
    H_appQNC gate ;
    gate.setModal(true) ;
    gate.exec() ;
    hide() ;
}


void H_FamGroupYN::on_No_clicked()
{
    H_appQNC gate ;
    gate.setModal(true) ;
    gate.exec() ;
    hide() ;
}

