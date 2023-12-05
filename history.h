#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>
#include "htable.h"
#include "facade_method.h"

namespace Ui {
class history;
}

class history : public QWidget
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = nullptr);
    void fill_table_buy_prod(HTable* temp);
    ~history();

private slots:
    void on_pushButton_clicked();

private:
    Ui::history *ui;
    enum Columna{
        INN_BUYER, COMPANY, INN, PRODUCT, COLVO
    };
};

#endif // HISTORY_H
