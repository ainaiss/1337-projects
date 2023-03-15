#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->Type = type;
}

Weapon::~Weapon()
{
    std::cout << "desctructor" << std::endl;
}

std::string const &Weapon::getType()
{
    return (this->Type);
}

void Weapon::setType(std::string type)
{
    this->Type = type;
}