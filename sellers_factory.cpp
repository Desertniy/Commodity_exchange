#include "sellers_factory.h"


factory_help *sellers_factory::create()
{
    return new Sellers();
}
