#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default Constructor" << std::endl;
	this->_type = "NULL";
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal Copy Constructor" << std::endl;
	*this = obj;
}

Animal	&Animal::operator = (const Animal &obj)
{
	if (this != &obj)
		this->_type = "NULL";
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "The animal make sound!" << std::endl;
}

std::string	Animal::getType() const
{
	return this->_type;
}