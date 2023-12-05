#ifndef BUYERS_FORM_H
#define BUYERS_FORM_H
#include "htable.h"
#include "facade_method.h"
#include <QWidget>

namespace Ui {
class Buyers_form;
}

class Buyers_form : public QWidget
{
    Q_OBJECT

public:
    explicit Buyers_form(QWidget *parent = nullptr);
    ~Buyers_form();



private slots:
    void on_pushButton_clicked();
    void fill_table_sellers(HTable *sell);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::Buyers_form *ui;

    enum Columna{
        INN, COMPANY, PRODUCT, COLVO
    };
};

#endif // BUYERS_FORM_H
