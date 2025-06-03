#include "baseobjectclass.h"

std::vector<Baseobjectclass*> Baseobjectclass::allObjects;

Baseobjectclass::Baseobjectclass(std::string name)
    : name(name)
{
    allObjects.push_back(this);
}

Baseobjectclass::~Baseobjectclass()
{
    std::cout<<"Base Object class constructor called"<<std::endl;
}

void Baseobjectclass::addChild(Baseobjectclass* child)
{
    children.push_back(child);
}

void Baseobjectclass::print()
{
    for (auto obj : allObjects)
    {
        std::cout << obj->GetName() << std::endl;
    }
}

std::string Baseobjectclass::GetName() const
{
    return name;
}
