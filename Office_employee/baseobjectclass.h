#ifndef BASEOBJECTCLASS_H
#define BASEOBJECTCLASS_H

#include <iostream>
#include <vector>
#include <string>

class Baseobjectclass {
protected:
    std::string name;
    std::vector<Baseobjectclass*> children;
    static std::vector<Baseobjectclass*> allObjects;

public:
    Baseobjectclass(std::string name);
    virtual ~Baseobjectclass();

    void addChild(Baseobjectclass* child);
    static void print();
    std::string GetName() const;

    virtual void getme() const = 0;
    virtual Baseobjectclass* findChild(const std::string& childName) = 0;
};

#endif
