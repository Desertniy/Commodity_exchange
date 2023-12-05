#ifndef SELLERS_H
#define SELLERS_H

#include "factory_help.h"
#include <string>
#include <estate.h>

class Sellers : public factory_help
{
public:
    Estate *getEst(QString inn, QString product, int count, QString company, QString inn_buyer);
};

#endif // SELLERS_H
