#ifndef HYBRIDENGINE_H
#define HYBRIDENGINE_H
#include "petrolengine.h"
#include "cngengine.h"
class Hybridengine:public Petrolengine,public CNGengine
{
public:
    Hybridengine(int a,int b);
    Hybridengine();
    ~Hybridengine();
};

#endif // HYBRIDENGINE_H
