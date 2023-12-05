#include "buy_prod_factory.h"


factory_help *buy_prod_factory::create()
{
    return new buy_prod();
}
