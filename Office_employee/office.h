#ifndef OFFICE_H
#define OFFICE_H

#include "baseobjectclass.h"

class Office : public Baseobjectclass {
public:
    Office();
    ~Office();
    void getme() const override;
    Baseobjectclass* findChild(const std::string& childName) override;
};

#endif
