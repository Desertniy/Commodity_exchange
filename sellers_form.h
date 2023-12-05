#ifndef SELLERS_FORM_H
#define SELLERS_FORM_H

#include <QWidget>
#include "facade_method.h"

namespace Ui {
class Sellers_form;
}

class Sellers_form : public QWidget
{
    Q_OBJECT

public:
    explicit Sellers_form(QWidget *parent = nullptr);
    ~Sellers_form();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Sellers_form *ui;
};

#endif // SELLERS_FORM_H
