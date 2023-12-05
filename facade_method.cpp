#include "facade_method.h"

facade_method::facade_method(QObject *parent)
    : QObject{parent}
{

}

void facade_method::final_create(QString inn, QString product, int count, QString company, QString inn_buyer, HTable *sel, HTable *buy, HTable *buy_prod)
{
    if (inn != inn_buyer){
        factory* create;
        factory_help* dop;
        Estate* temp;
        if (inn_buyer == ""){
            create = new sellers_factory();
            dop = create->create();
            temp = dop->getEst(inn, product, count, company, "");
            if (sel->inn_check(temp, sel, temp->getInn()) && buy->inn_check(temp, buy, temp->getInn()))
                sel->add_tab(temp, sel);

        }
        else{
            create = new buy_prod_factory();
            dop = create->create();
            temp = dop->getEst(inn, product, count,  company, inn_buyer);
            if (sel->comparison(temp, sel)){
                buy_prod->add_tab(temp, buy_prod);
                if (buy->find(inn_buyer, buy) == -1){
                    create = new buyers_factory();
                    dop = create->create();
                    temp = dop->getEst(inn_buyer, "", 0,  company, "");
                    buy->add_tab(temp, buy);
                }
            }
        }
    }
}








void facade_method::del_elem(QString inn, QString prod, HTable *sel, HTable *buy_prod)
{
    if (sel != nullptr){
        if (prod != ""){
            if (!buy_prod->availability_in_sold(inn, prod, buy_prod))
                sel->del(inn, prod, sel);
        }
        else{
            sel->del(inn, sel);
        }
    }
}



