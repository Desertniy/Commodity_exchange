#ifndef HTABLE_H
#define HTABLE_H

#include <QObject>
#include "estate.h"
#include <QRegularExpression>
#include <string>

const int table_len = 10;
const int key_len = 9;
class HTable : public QObject
{
    Q_OBJECT
    class Node
       {
       public:
           QString product = "";
           QString company = "";
           QString inn = "";
           QString inn_buyer = "";
           int count = 0;
    };

    Node* head;
public:
    explicit HTable(QObject *parent = nullptr);
    int size = 0;
    bool inn_check(Estate* temp, HTable* list, QString k);
    bool is_key(QString key);
    int hash(QString key);
    int find(QString key, HTable* list);
    void add_tab(Estate* temp, HTable *list);
    void check_company(QString comp, QString inn, HTable* list);
    void del(QString key, HTable *list);
    void del(QString key, QString prod, HTable *list);
    bool availability_in_sold(QString key, QString prod, HTable *list);
    QString prod(HTable *list, int i);
    QString comp(HTable *list, int i);
    QString in(HTable *list, int i);
    QString inn_b(HTable *list, int i);
    int cnt(HTable *list, int i);
    bool status(HTable* list, int i);
    bool comparison(Estate* temp, HTable* main);
};

inline HTable sellers_main[table_len];
inline HTable buyers_main[table_len];
inline HTable b_p_main[table_len];
#endif // HTABLE_H
