#include "buyers_form.h"
#include "ui_buyers_form.h"


Buyers_form::Buyers_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Buyers_form)
{
    QStringList titulos;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    titulos << "ИНН продавца" << "Компания" << "Продукт" << "Кол-во";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
    fill_table_sellers(sellers_main);

}

Buyers_form::~Buyers_form()
{
    delete ui;
}

void Buyers_form::on_pushButton_clicked()
{
    QString company = ui->lineEdit->text();
    QString inn = ui->lineEdit_3->text();
    QString product = ui->lineEdit_4->text();
    int count = ui->lineEdit_5->text().toInt();
    QString inn_buyer = ui->lineEdit_2->text();
    facade_method::final_create(inn, product, count, company, inn_buyer, sellers_main, buyers_main, b_p_main);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    fill_table_sellers(sellers_main);
}

void Buyers_form::fill_table_sellers(HTable *sell)
{
    ui->tableWidget->setRowCount(0);
    for (int i = 0; i < table_len; i++){
        if (sell->status(sell, i)){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, INN, new QTableWidgetItem(sell->in(sell, i)));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, COMPANY, new QTableWidgetItem(sell->comp(sell, i)));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, PRODUCT, new QTableWidgetItem(sell->prod(sell, i)));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, COLVO, new QTableWidgetItem(QString::number(sell->cnt(sell, i))));
        }
    }
}


void Buyers_form::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}


void Buyers_form::on_pushButton_3_clicked()
{
    QWidget::close();
}



