#include "sellers.h"


Estate *Sellers::getEst(QString inn, QString product, int count, QString company, QString inn_buyer)
{
    return new Estate(inn, product, count, company, inn_buyer);

}
