#include "buyers_factory.h"



factory_help *buyers_factory::create()
{
    return new Buyers();
}
