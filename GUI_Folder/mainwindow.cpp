#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include "login.h"
#include <QMessageBox>
#include "input_window.h"
#include "vip.h"
#include "ui_login.h"
#include "newcomeryn.h"
#include "ui_input_window.h"
#include "ui_newcomeryn.h"
#include "family.h"
#include "ui_vip.h"
#include "ui_family.h"
#include "goto.h"
#include "no_of_ppl.h"
#include "ui_no_of_ppl.h"
#include "ui_goto.h"
#include "switch_info.h"
#include "ui_switch_info.h"
#include "switch_to_gate.h"
#include "ui_switch_to_gate.h"
#include "q_status.h"
#include "ui_q_status.h"
#include "class.cpp"
#include <unistd.h>

EntryQueueManager EQM;
int capacity;
int capacity_vip;
int  remaining_total;
int remaining_total_V;
int poptime;
int time_of_entry = 60;
 int remaining, remainingV;
int max_time;
 int time_total;
 int checker = 0;
 int group_checker  = 0;
 int group;
 int vip ;
 int family;
 int moving_queue;
 int new_comer =0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/Desktop/png-clipart-queueing-theory-priority-queue-stack-abstract-data-type-others-miscellaneous-computer-network.png");
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
    do{
        LOGIN login_aud;
        login_aud.setModal(true);
        login_aud.exec();
    }while((remaining_total != 0 || remaining_total_V != 0) && checker != max_time);
}


LOGIN::LOGIN(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LOGIN)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/Desktop/login.jpg");
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

    if (username == "test" && password == "1234") {  //audiende
        QMessageBox::information(this, "LoginIn", "Loged in Successfull");
        hide();




        //ADD CODE FOR NEXT PAGE FOR AUDIENCE

    }
    else if(username == "test1" && password == "1234"){ //stadium authority
        QMessageBox::information(this, "LoginIn", "Loged in Successfull");
        hide() ;
        INPUT_WINDOW ip_stad;
        ip_stad.setModal(true);
        ip_stad.exec();


    }
    else
        QMessageBox::warning(this, "Login", "Username and Password incorrect");
}


//---------------------------------------------------------------------


INPUT_WINDOW::INPUT_WINDOW(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::INPUT_WINDOW)
{
    ui->setupUi(this);
}

INPUT_WINDOW::~INPUT_WINDOW()
{
    delete ui;
}

void INPUT_WINDOW::on_pushButton_Done_clicked()
{
    hide();
    int capacity = ui->LineEdit_M->text().toInt();
    int NValue = ui->lineEdit_N->text().toInt();
    poptime = ui->lineEdit_p->text().toInt();
    int capacity_vip = ui->VIP_Cp->text().toInt();
    int GValue = ui->VIP_gt->text().toInt();
    QMessageBox::information(this, "Input Window", "Data Recorded Successfully");
    hide();

    max_time = time_of_entry / poptime;
    capacity = capacity - capacity_vip;
    NValue = NValue - GValue;
    EQM.SetData(capacity,NValue,GValue,capacity_vip);
    EQM.RandomAssignment_initial();
    EQM.RandomAssignmentVip_initial();
    EQM.display();

    remaining_total_V = capacity_vip / 2;
    remaining_total = capacity / 2;

}

//-----------------------------------------------------------------------------------------------


VIP::VIP(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VIP)
{
    ui->setupUi(this);
}

VIP::~VIP()
{
    delete ui;
}

void VIP::on_radioButton_clicked()
{
    hide();
    remaining = capacity / 2;
    remainingV = capacity_vip / 2 - 1;   //vip yes 0
                                            // vip no 1
    vip = 1;
    NEWCOMERYN np_yn;
    np_yn.setModal(true);
    np_yn.exec();
    hide();
}


void VIP::on_radioButton_2_clicked()
{
    hide();
    vip = 0;
    remaining = capacity / 2 - 1;
    remainingV = capacity_vip / 2;
    NEWCOMERYN np_yn;
    np_yn.setModal(true);
    np_yn.exec();
    hide();
}



//------------------------------------------------------------------------------------------------
NEWCOMERYN::NEWCOMERYN(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NEWCOMERYN)
{
    ui->setupUi(this);
}

NEWCOMERYN::~NEWCOMERYN()
{
    delete ui;
}

void NEWCOMERYN::on_Yes_clicked()
{
    new_comer =1;
    FAMILY fam_yn;
    fam_yn.setModal(true);
    fam_yn.exec();
    hide();
}


void NEWCOMERYN::on_No_clicked()
{
    new_comer = 0;
    SWITCH_INFO switch_ppl;
    switch_ppl.setModal(true);
    switch_ppl.exec();
    hide();

}

//*****--------------------------------------------------------------------------------------------

FAMILY::FAMILY(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FAMILY)
{
    ui->setupUi(this);
}

FAMILY::~FAMILY()
{
    delete ui;
}

void FAMILY::on_Yes_clicked()

{
    family = 1;
    // GOTO gate_fam;
    // gate_fam.setModal(true);
    // gate_fam.exec();
    // hide();


    NO_OF_PPL no_ppl;
    no_ppl.setModal(true);
    no_ppl.exec();

}


void FAMILY::on_No_clicked()
{
    family = 0;
    if (vip == 1){
    moving_queue = EQM.InsertNewVip(1, group_checker);
    remaining_total_V--;
    }
    else if (vip== 0){
        moving_queue = EQM.InsertNew(1, group_checker);
        remaining_total--;
    }
    GOTO gate_single;
    gate_single.setModal(true);
    gate_single.exec();
    hide();
}

//************************************************************************************************

NO_OF_PPL::NO_OF_PPL(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NO_OF_PPL)
{
    ui->setupUi(this);

}

NO_OF_PPL::~NO_OF_PPL()
{
    delete ui;
}
void NO_OF_PPL::on_Done_clicked()
{
    group = ui->NoPeople->text().toInt();

    hide() ;
    family = 1;
    if (vip == 1 && new_comer ==1){
    group_checker = group;
    moving_queue = EQM.InsertNewVip(1, group_checker);
    remaining_total_V -= group_checker;
    remainingV = remainingV - group_checker + 1;


    }


    else if(vip ==0){
        group_checker = group;
        moving_queue = EQM.InsertNew(1, group_checker);
        remaining_total -= group_checker;
        remaining = remaining - group_checker + 1;
    }
    GOTO go_to;
    go_to.setModal(true);
    go_to.exec();
}

//-----------------------------------------------------------------------------------------------


GOTO::GOTO(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GOTO)
{
    ui->setupUi(this);
    if (vip ==0)
    updateNumber(moving_queue , EQM.waiting_time(moving_queue,poptime));
    else
    updateNumber(moving_queue , EQM.waiting_time_vip(moving_queue,poptime));

}

GOTO::~GOTO()
{
    delete ui;
}
// void GOTO::on_pushButton_clicked()
// {
//      // Done button
// }

void GOTO::updateNumber(int gateNoValue, int waitTimeValue)
{
    QString switchToText = QString::number(gateNoValue);
    QString waitTimeText = QString::number(waitTimeValue);

    // Set the text of the QLabel widgets
    ui->GateNoNC_2->setText(switchToText);
    ui->WaitTimeNC_2->setText(waitTimeText);
}




void GOTO::on_pushButton_2_clicked()
{
    hide() ;


}

//------------------------------------------------------------------------------------------------

SWITCH_INFO::SWITCH_INFO(QWidget *parent)
    : QDialog(parent)

    , ui(new Ui::SWITCH_INFO)
{
    ui->setupUi(this);
}

SWITCH_INFO::~SWITCH_INFO()
{
    delete ui;
}

void SWITCH_INFO::on_Yes_clicked()
{

    int val = ui->GateInfo->text().toInt();
    SWITCH_TO_GATE gate_no ;
    gate_no.setModal(true) ;
    gate_no.exec() ;
    hide() ;
}

void SWITCH_INFO::on_No_clicked()
{
    QMessageBox::warning(this, "warning" , "Sorry, ypu cannot switch queues!") ;
    hide() ;
}

//--------------------------------------------------------------------------------------------------

SWITCH_TO_GATE::SWITCH_TO_GATE(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SWITCH_TO_GATE)
{
    ui->setupUi(this);
}

SWITCH_TO_GATE::~SWITCH_TO_GATE()
{
    delete ui;
}

void SWITCH_TO_GATE::on_pushButton_clicked()
{
    hide();
    Q_STATUS data;
    data.setModal(true);
    data.exec();

}

//------------------------------------------------------------------------------------------


Q_STATUS::Q_STATUS(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Q_STATUS)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    onSentenceReceived("Hello! How ya doin'?");
}

Q_STATUS::~Q_STATUS()
{
    delete ui;
}

void Q_STATUS::appendSentence(const QString& sentence) {
    ui->textEdit->append(sentence) ;
}

void Q_STATUS::onSentenceReceived(const QString& sentence){
    appendSentence(sentence) ;
}

void Q_STATUS::on_pushButton_clicked()
{
    VIP np_yn;
    np_yn.setModal(true);
    np_yn.exec();

}







