 #include "WrongAnimal.hpp"
 
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default Constructor" << std::endl;
	this->_type = "NULL";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
	*this = obj;
}

WrongAnimal	&WrongAnimal::operator = (const WrongAnimal &obj)
{
	if (this != &obj)
		this->_type = "NULL";
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "The WrongAnimal make sound!" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}
