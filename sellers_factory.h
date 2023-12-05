#ifndef SELLERS_FACTORY_H
#define SELLERS_FACTORY_H

#include "factory.h"
#include "sellers.h"

class sellers_factory : public factory
{
public:
    factory_help *create();
};

#endif // SELLERS_FACTORY_H
