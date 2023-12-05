#include "mainwindow.h"
#include "ui_mainwindow.h"


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


void MainWindow::on_pushButton_clicked()
{
    sellers_form = new Sellers_form();
    sellers_form->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    buyers_form = new Buyers_form();
    buyers_form->show();

}


void MainWindow::on_pushButton_3_clicked()
{
    history_from = new history();
    history_from->show();
}

