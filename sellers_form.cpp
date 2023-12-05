#include "sellers_form.h"
#include "ui_sellers_form.h"

Sellers_form::Sellers_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sellers_form)
{
    ui->setupUi(this);
}

Sellers_form::~Sellers_form()
{
    delete ui;
}

void Sellers_form::on_pushButton_clicked()
{
    QString company = ui->lineEdit->text();
    QString inn = ui->lineEdit_2->text();
    QString product = ui->lineEdit_3->text();
    int count = ui->lineEdit_4->text().toInt();
    facade_method::final_create(inn, product, count, company, "", sellers_main, buyers_main, b_p_main);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}


void Sellers_form::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}


void Sellers_form::on_pushButton_3_clicked()
{
    QWidget::close();
}


void Sellers_form::on_pushButton_5_clicked()
{
    QString inn = ui->lineEdit_7->text();
    QString prod = ui->lineEdit_5->text();
    facade_method::del_elem(inn, prod, sellers_main, b_p_main);
    ui->lineEdit_7->clear();
    ui->lineEdit_5->clear();
}

