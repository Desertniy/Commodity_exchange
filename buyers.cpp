#include "buyers.h"

Estate *Buyers::getEst(QString inn, QString product, int count, QString company, QString inn_buyer)
{
    return new Estate(inn, "", 0, company, "");
}
