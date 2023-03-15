#ifndef __BASE__HPP
#define __BASE__HPP
#include <iostream>
#include <string.h>

class Base {
    public:
        virtual ~Base(){};
};

class BaseA : public Base {};
class BaseB : public Base {};
class BaseC : public Base {};
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif