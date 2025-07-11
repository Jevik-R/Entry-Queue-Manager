#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "h_inputwindow.h"
#include "h_newcomeryn.h"
// #include "h_famgroupyn.h"
// #include "h_appqnc.h"
// #include "h_switchinfo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hide() ;
    H_InputWindow Input ;
    Input.setModal(true) ;
    Input.exec() ;
    hide() ;
    H_NewComerYN value ;
    value.setModal(true);
    value.exec() ;
    hide() ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::onYesClicked(){
//     H_FamGroupYN yn ;
//     yn.setModal(true) ;
//     yn.exec() ;
//     hide() ;
// }
// void MainWindow::onNoClicked()
// {
//     H_SwitchInfo info;
//     info.setModal(true);
//     info.exec();
// }

