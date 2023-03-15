#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->_Hit_points = 100;
	this->_Energy_points = 100;
	this->_Attack_damage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "Parameterised FragTrap constructor called" << std::endl;
	this->_name = name;
	this->_Hit_points = 100;
	this->_Energy_points = 100;
	this->_Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &obj)
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
	*this = obj;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "Assignment FragTrap operator called" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_Attack_damage = obj._Attack_damage;
		this->_Energy_points = obj._Energy_points;
		this->_Hit_points = obj._Hit_points;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "High Fives Guys called" << std::endl;
}

void	FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap " << _name << " attack " << target << " causing "
	<< _Attack_damage << " points of damage!" << std::endl;
}
