#include "WrongCat.hpp" 

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default Constructor" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj)
{
	std::cout << "WrongCat Copy Constructor" << std::endl;
	*this = obj;
}

WrongCat	&WrongCat::operator = (const WrongCat &obj)
{
	if (this != &obj)
		this->_type = "WrongCat";
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "The WrongCat make sound!" << std::endl;
}
