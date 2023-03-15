#include "HumanB.hpp"

HumanB::HumanB(std::string name): Name(name)
{
    std::cout << "constructor HumanB" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "desctructor HumanB" << std::endl;
}

std::string HumanB::getname()
{
    return (this->Name);
}

void HumanB::setname(std::string name)
{
    this->Name = name;
}

void HumanB::attack()
{
    if (this->_Weapon != NULL){
    std::cout << this->getname() << " attacks with their " << _Weapon->getType() << std::endl;
    }
}

void HumanB::setWeapon(Weapon &Weapon)
{
    this->_Weapon = &Weapon;
}
