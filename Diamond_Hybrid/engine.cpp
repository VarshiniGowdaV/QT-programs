#include "engine.h"
#include <iostream>
using namespace std;
Engine::Engine(int a,int b)
{
    m_a=a;
    m_b=b;
    cout<<"Engine construtor called "<<endl;
}
Engine::Engine()
{
    cout<<"Engine default contrutor called"<<endl;
}
Engine::~Engine()
{
    cout<<"Engine distructor called "<<endl;
}
void Engine::startengine()
{
    cout<<"a:"<<m_a<<endl;
    cout<<"b:"<<m_b<<endl;
    cout<<"Engine starting"<<endl;
}
