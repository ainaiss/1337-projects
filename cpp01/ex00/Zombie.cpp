#include "Zombie.hpp"


Zombie::Zombie()
{
    std::cout << "constructor" << std::endl;
}
Zombie::Zombie(std::string name)
{
    std::cout << "constructor" << std::endl;
    this->_name = name;
}


Zombie::~Zombie()
{
    std::cout << "destructor" << std::endl;
}

std::string Zombie::get_zombie_name()
{
    return(this->_name);
}

void    Zombie::set_zombie_name(std::string name)
{
    this->_name = name;
}

void   Zombie::announce(void)
{
    std::cout << this->get_zombie_name() << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}