#ifndef BUYERS_FACTORY_H
#define BUYERS_FACTORY_H

#include "factory.h"
#include "buyers.h"

class buyers_factory : public factory
{
public:
    factory_help *create();
};

#endif // BUYERS_FACTORY_H
