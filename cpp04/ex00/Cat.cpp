#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &obj)
{
	std::cout << "Cat Copy Constructor" << std::endl;
	*this = obj;
}

Cat	&Cat::operator = (const Cat &obj)
{
	if (this != &obj)
		this->_type = "Cat";
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "The Cat make sound!" << std::endl;
}

