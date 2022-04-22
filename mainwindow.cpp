#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLabel>
#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//






//add element
void MainWindow::on_pushButton_clicked()
{

    QString first = ui->lineEdit->text();

    QString second = ui->lineEdit_2->text();



    if (first == "" || second == ""){
        QMessageBox::critical(this, "Error", "You should pass args");
        return;
    }



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


//intersect
void MainWindow::on_pushButton_2_clicked()
{

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


//clear first set
void MainWindow::on_pushButton_6_clicked()
{
    v1.clear();
    ui->f_set->setText("");

}


//clear second
void MainWindow::on_pushButton_7_clicked()
{
    v2.clear();
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

//sim sub
void MainWindow::on_pushButton_4_clicked()
{
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
