#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->_Hit_points = 100;
	this->_Energy_points = 50;
	this->_Attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Parametrised ScavTrap constructor called" << std::endl;
	this->_name = name;
	this->_Hit_points = 100;
	this->_Energy_points = 50;
	this->_Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_Attack_damage = obj._Attack_damage;
		this->_Energy_points = obj._Energy_points;
		this->_Hit_points = obj._Hit_points;
	}
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "GuardGate called" << std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << _name << " attack " << target << " causing "
	<< _Attack_damage << " points of damage!" << std::endl;
}
