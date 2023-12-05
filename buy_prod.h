#ifndef BUY_PROD_H
#define BUY_PROD_H

#include "factory_help.h"
#include <string>
#include <estate.h>

class buy_prod : public factory_help
{
public:
    Estate *getEst(QString inn, QString product, int count, QString company, QString inn_buyer);
};

#endif // BUY_PROD_H
