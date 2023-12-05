#include "estate.h"

Estate::Estate(QObject *parent)
    : QObject{parent}
{

}

Estate::Estate(QString inn, QString product, int count, QString company, QString inn_buyer)
{
    this->company = company;
    this->inn = inn;
    this->product = product;
    this->count = count;
    this->inn_buyer = inn_buyer;
}

QString Estate::getCompany()
{
    return this->company;
}

QString Estate::getInn()
{
    return this->inn;
}

QString Estate::getProd()
{
    return this->product;
}

int Estate::getCount()
{
    return this->count;
}

QString Estate::getInnBuyer()
{
    return this->inn_buyer;
}


