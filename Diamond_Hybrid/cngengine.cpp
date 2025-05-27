#include "cngengine.h"
#include "engine.h"
#include <iostream>
using namespace std;
CNGengine::CNGengine(int a,int b):Engine(a,b)
{
    cout<<"CNGengine constructor called"<<endl;
}
CNGengine::CNGengine()
{
    cout<<"CNGengine default constructor called"<<endl;
}
CNGengine::~CNGengine()
{
    cout<<"CNGengine distructor called"<<endl;
}
