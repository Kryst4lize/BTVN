#include<iostream>

#define gfg 401

#if gfg > 200
#undef gfg
#define gfg 30
#elif gfg < 50
#undef gfg
#define gfg 50
#else
#undef gfg
#define gfg 100
#endif

int mainpre()
{
    std::cout << gfg;  // gfg = 50
    return 0;
}