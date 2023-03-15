#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
 #include "Weapon.hpp"

class HumanA
{
    private:
     std::string  Name;
     Weapon     &_Weapon;
    public:
    HumanA(std::string name, Weapon &Weapon);
    ~HumanA();
    std::string getname();
    void attack();
    void setname(std::string name);
};

#endif