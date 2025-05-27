#include "hybridengine.h"
#include <iostream>
using namespace std;
Hybridengine::Hybridengine(int a,int b):Petrolengine(a,b),CNGengine(a,b),Engine(a,b)
{
    cout<<"Hybridengine constructor called"<<endl;
}
Hybridengine::Hybridengine()
{
    cout<<"Hybridengine default constructor called"<<endl;
}
Hybridengine::~Hybridengine()
{
    cout<<"Hybridengine distructor called"<<endl;
}
