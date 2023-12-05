#ifndef FACADE_METHOD_H
#define FACADE_METHOD_H

#include <QObject>
#include "factory.h"
#include "buyers_factory.h"
#include "buy_prod_factory.h"
#include "sellers_factory.h"
#include "estate.h"
#include "htable.h"
#include <string>


class facade_method : public QObject
{
    Q_OBJECT
public:
    explicit facade_method(QObject *parent = nullptr);
    static void final_create(QString inn, QString product, int count, QString company, QString inn_buyer, HTable* sel, HTable* buy, HTable* buy_prod);
    static void del_elem(QString inn, QString prod = "", HTable* sel = nullptr, HTable* buy_prod = nullptr);

signals:

};

#endif // FACADE_METHOD_H
