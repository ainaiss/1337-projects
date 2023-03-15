#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon): Name(name), _Weapon(Weapon)
{
    std::cout << "constructor HumanA" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "desctructor HumanA" << std::endl;
}

std::string HumanA::getname()
{
    return (this->Name);
}

void HumanA::setname(std::string name)
{
    this->Name = name;
}

void HumanA::attack()
{
    std::cout << this->getname() << " attacks with their " << _Weapon.getType() << std::endl;
}

