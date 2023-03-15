#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "default constructor" << std::endl;
    _Hit_points = 10;
    _Energy_points = 10;
    _Attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "parameterized constructor" << std::endl;
    _name = name;
    _Hit_points = 10;
    _Energy_points = 10;
    _Attack_damage = 0;
}

ClapTrap::~ClapTrap(){
    std::cout << "destructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
  std::cout << "copy constructor" << std::endl;
  *this = obj;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Assignment Operator" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_Attack_damage = obj._Attack_damage;
		this->_Energy_points = obj._Energy_points;
		this->_Hit_points = obj._Hit_points;
	}
	return *this;
}

void	ClapTrap::setname(std::string name)
{
	this->_name = name;
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << _name << " attack " << target << " causing "
	<< _Attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "takeDamage called with amount: " << amount << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "beRepaired Called with amount: " << amount << std::endl;
}

