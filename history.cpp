#include "history.h"
#include "ui_history.h"

history::history(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
    QStringList titulos;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    titulos << "ИНН покупателя" << "Компания" << "Инн продавца" << "Продукт" << "Кол-во";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
    fill_table_buy_prod(b_p_main);
}

void history::fill_table_buy_prod(HTable *temp)
{
    ui->tableWidget->setRowCount(0);
    for (int i = 0; i < table_len; i++){
        if (temp->status(temp, i)){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, INN_BUYER, new QTableWidgetItem(temp->inn_b(temp, i)));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, COMPANY, new QTableWidgetItem(temp->comp(temp, i)));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, INN, new QTableWidgetItem(temp->in(temp, i)));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, PRODUCT, new QTableWidgetItem(temp->prod(temp, i)));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, COLVO, new QTableWidgetItem(QString::number(temp->cnt(temp, i))));
        }
    }
}

history::~history()
{
    delete ui;
}

void history::on_pushButton_clicked()
{
    QWidget::close();
}

