#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>


using namespace std;

QString num1;
QString num2;

int reverse1(int num){
    int num3=0;
    while(num!=0){
        num3 = num3*10+(num%10);
        num/=10;
    }
    return num3;
}

int getLargestPalindrome(int n1,int n2){
    if(n1==n2)
        return -1;
    if(n2==reverse1(n2))
        return n2;
    return getLargestPalindrome(n1,n2-1);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    num1 = ui->lineEdit->text();
    num2 = ui->lineEdit_2->text();
    double n1 = num1.toDouble();
    double n2 = num2.toDouble();
    int largest = 0;


    if((n1-int(n1)!=0)||(n2-int(n2)!=0))
    {
        n1=int(n1);
        n2=int(n2);

    }







    if(n1<=0 && n2<=0)
        ui->label_3->setText("Invalid Input:Please enter a number greater than zero");



    else if(n1>n2){
        largest = getLargestPalindrome(n2,n1);
        if(largest != -1)
            ui->label_3->setText("The largest palindrome number between the two numbers is: "+QString::number(largest));
        else
            ui->label_3->setText("There are no palindrome numbers between the given numbers");
    }


    else if(n1<n2){
        largest = getLargestPalindrome(n1,n2);
        if(largest != -1)
            ui->label_3->setText("The largest palindrome number between the two numbers is: "+QString::number(largest));
        else
            ui->label_3->setText("There are no palindrome numbers between the given numbers");
    }





    else
        ui->label_3->setText("Number are equals no palindrome can be found between them.");

}

void MainWindow::on_pushButton_2_clicked()
{
    QApplication::exit();
}

void MainWindow::on_lineEdit_editingFinished()
{

    num1 = ui->lineEdit->text();


    QRegExp re("\\d*");


    if(re.exactMatch(num1))
        ui->label_6->setText("<font color='green'> VALID");
    else
        ui->label_6->setText("<font color='red'> INVALID");



}

void MainWindow::on_lineEdit_2_editingFinished()
{

    num2 = ui->lineEdit->text();

    QRegExp re("\\d*");


    if(re.exactMatch(num2))
        ui->label_7->setText("<font color='green'> VALID");
    else
        ui->label_7->setText("<font color='red'> INVALID");

}
