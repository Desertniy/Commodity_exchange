#ifndef BUYERS_H
#define BUYERS_H

#include "factory_help.h"
#include <string>
#include <estate.h>
class Buyers : public factory_help
{
public:
    Estate *getEst(QString inn, QString product, int count, QString company, QString inn_buyer);
};

#endif // BUYERS_H
