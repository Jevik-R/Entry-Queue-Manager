#include "h_inputwindow.h"
#include "ui_h_inputwindow.h"
#include <QMessageBox>

H_InputWindow::H_InputWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::H_InputWindow)
{
    ui->setupUi(this);
}

H_InputWindow::~H_InputWindow()
{
    delete ui;
}

void H_InputWindow::on_pushButton_Done_clicked()
{
    int MValue = ui->LineEdit_M->text().toInt();
    int NValue = ui->lineEdit_N->text().toInt();
    int pValue = ui->lineEdit_p->text().toInt();

    // QMessageBox::information(this, "Status","Information set!") ;
    // QString M = ui->LineEdit_M->text();
    // QString N = ui->lineEdit_N->text();
    // QString p = ui->lineEdit_p->text();

    // // Convert the validated input to integers
    // int MValue = M.toInt();
    // int NValue = N.toInt();
    // int pValue = p.toInt();
    // Now you can use MValue, NValue, and pValue as integers

    // if( ((MValue >= 32 && MValue <= 47) || (MValue >= 58 && MValue <= 126) ||
    //      (NValue >= 32 && NValue <= 47) || (NValue >= 58 && NValue <= 126) ||
    //      (pValue >= 32 && pValue <= 47) || (pValue >= 58 && pValue <= 126)) )
    // {
    //     QMessageBox::warning(this, "Warning" , "Please enter valid information!");
    // }
    // else{
    //     QMessageBox::information(this, "Status","Information set!") ;
    // }
    hide() ;
}

// void H_InputWindow::on_pushButton_Done_clicked()
// {
//     QString M = ui->LineEdit_M->text();
//     QString N = ui->lineEdit_N->text();
//     QString p = ui->lineEdit_p->text();

//     // Check if any of the inputs are not numeric
//     bool invalidInput = false;
//     int MValue = M.toInt(&invalidInput);
//     int NValue = N.toInt(&invalidInput);
//     int pValue = p.toInt(&invalidInput);

//     // If any of the inputs are not numeric, display a warning message
//     if (invalidInput) {
//         QMessageBox::information(this, "Warning", "Please enter valid numeric information!");
//     } else {
//         // Now you can use MValue, NValue, and pValue as integers

//         // Additional checks or actions can be performed here
//         QMessageBox::information(this, "Status", "Information set!");
//     }
// }

