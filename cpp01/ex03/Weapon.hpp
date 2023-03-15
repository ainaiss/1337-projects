#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string Type;

public:
    Weapon(std::string type);
    ~Weapon();

    std::string const &getType();
    void setType(std::string type);
};

#endif