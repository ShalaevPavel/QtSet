#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPainter>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Integers");
    ui->comboBox->addItem("Strings");
    //reply = QMessageBox::question(this, "", "Would you like to work with a set of integers?",
                          //QMessageBox::Yes|QMessageBox::No);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//add element
void MainWindow::on_pushButton_clicked()
{



    QString first = ui->lineEdit->text();

    QString second = ui->lineEdit_2->text();



    if (first == "" || second == ""){
        QMessageBox::critical(this, "Error", "You should pass args");
        return;
    }

    if (ui->comboBox->currentText() == "Integers"){

    int f1= first.toInt();
    int s1 = second.toInt();
    v1.push_back(f1);
    v2.push_back(s1);


    QString str = "";
    foreach (auto i, v1){
    str += QString::number(i);
    str += "\n";
    }
    ui->f_set ->setText(str);


    QString str2 = "";
    foreach (auto i, v2){
    str2 += QString::number(i);
    str2 += "\n";
    }
    ui->s_set ->setText(str2);

    }

    else{
        vs1.push_back(first.toStdString());
        vs2.push_back(second.toStdString());
        QString str = "";
        foreach (auto i, vs1){
        str += QString::fromStdString(i);
        str += "\n";
        }
        ui->f_set ->setText(str);


        QString str2 = "";
        foreach (auto i, vs2){
        str2 += QString::fromStdString(i);
        str2 += "\n";
        }
        ui->s_set ->setText(str2);



    }


}


//intersect
void MainWindow::on_pushButton_2_clicked()
{

    if (ui->comboBox->currentText() == "Integers"){
    IntegerSet first_set(v1);
    IntegerSet second_set(v2);

    My_set res = first_set.mult(second_set);

    QString str = "";
    foreach (auto i, res.my_set){
    str += QString::number(i);
    str += "\n";
    }
    ui->l_set ->setText(str);
    }
    else{
        StringSet first_set(vs1);
        StringSet second_set(vs2);

        My_set res = first_set.mult(second_set);
        if (res.my_string_set.size()== 1 && res.my_string_set[0] == ""){
            QMessageBox::critical(this, "error", "Unable to intersect");
        }
        QString str = "";
        foreach (auto i, res.my_string_set){
        str += QString::fromStdString(i);
        str += "\n";
        }
        ui->l_set ->setText(str);
        }



}


//clear first set
void MainWindow::on_pushButton_6_clicked()
{
    if (ui->comboBox->currentText() == "Integers"){
    v1.clear();
    }
    else{
        vs1.clear();
    }
    ui->f_set->setText("");

}


//clear second
void MainWindow::on_pushButton_7_clicked()
{
    if (ui->comboBox->currentText() == "Integers"){
    v2.clear();
    }
    else{
        vs2.clear();
    }
    ui->s_set->setText("");
}

//clear third
void MainWindow::on_pushButton_5_clicked()
{
    ui->l_set->setText("");
}

//union
void MainWindow::on_pushButton_3_clicked()
{
    if (ui->comboBox->currentText() == "Integers"){
    IntegerSet first_set(v1);
    IntegerSet second_set(v2);

    My_set res = first_set.add(second_set);
    QString str = "";
    foreach (auto i, res.my_set){
    str += QString::number(i);
    str += "\n";
    }
    ui->l_set ->setText(str);
    }
    else{
        StringSet first_set(vs1);
        StringSet second_set(vs2);

        My_set res = first_set.add(second_set);
        QString str = "";
        foreach (auto i, res.my_string_set){
        str += QString::fromStdString(i);
        str += "\n";
        }
        ui->l_set ->setText(str);
        }



}

//sim sub
void MainWindow::on_pushButton_4_clicked()
{
    if (ui->comboBox->currentText() == "Integers"){

    IntegerSet first_set(v1);
    IntegerSet second_set(v2);

    My_set res = first_set.sim_sub(second_set);
    QString str = "";
    foreach (auto i, res.my_set){
    str += QString::number(i);
    str += "\n";
    }
    ui->l_set ->setText(str);
    }
    else{

        StringSet first_set(vs1);
        StringSet second_set(vs2);

        My_set res = first_set.sim_sub(second_set);
        QString str = "";
        foreach (auto i, res.my_string_set){
        str += QString::fromStdString(i);
        str += "\n";
        }
        ui->l_set ->setText(str);

    }
}






