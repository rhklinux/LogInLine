#include "custom.h"


logger& operator<<(logger& os, const custom_t& c)
{
    os << "Data is : " << c.member;
    return os;
}


