#include "petrolengine.h"
#include <iostream>
using namespace std;
Petrolengine::Petrolengine(int a,int b):Engine(a,b)
{
    cout<<"Petrol engine constructor called"<<endl;
}
Petrolengine::Petrolengine()
{
    cout<<" Petrolengine default constructor called"<<endl;
}
Petrolengine::~Petrolengine()
{
    cout<<"Petrol engine distructor called"<<endl;
}
