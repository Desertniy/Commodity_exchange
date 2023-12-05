#ifndef BUY_PROD_FACTORY_H
#define BUY_PROD_FACTORY_H

#include "factory.h"
#include "factory_help.h"
#include "buy_prod.h"

class buy_prod_factory : public factory
{
public:
    factory_help *create();
};

#endif // BUY_PROD_FACTORY_H
