#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constructor" << std::endl;
	this->_type = "Dog";
	this->br = new Brain();
}

Dog::Dog(const Dog &obj)
{
	std::cout << "Dog Copy Constructor" << std::endl;
	*this = obj;
}

Dog	&Dog::operator = (const Dog &obj)
{
	if (this != &obj)
	{
		this->_type = "Dog";
		this->br = new Brain();
		*this->br = *obj.br;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
	delete this->br;
}

void	Dog::makeSound() const
{
	std::cout << "The Dog make sound!" << std::endl;
}

// void	Dog::getBrain() const
// {
// 	this->br->getBrain();
// }

// void	Dog::setBrain(std::string str)
// {
// 	this->br->setbrain(str);
// }

