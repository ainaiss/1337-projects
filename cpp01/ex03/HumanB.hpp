#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
 #include "Weapon.hpp"

class HumanB
{
    private:
     std::string  Name;
     Weapon     *_Weapon;
    public:
    HumanB(std::string name);
    ~HumanB();
    std::string getname();
    void attack();
    void setname(std::string name);
    void setWeapon(Weapon &Weapon);
};

#endif