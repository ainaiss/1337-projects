#include "Brain.hpp"
#include <string>

Brain::Brain()
{
	std::cout << "Brain Default constructor" << std::endl;
}

Brain::Brain(const Brain &br)
{
	std::cout << "Brain Copy constructor" << std::endl;
	*this = br;
}

Brain	&Brain::operator=(const Brain &obj)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &obj)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	return *this;
}

// void	Brain::getBrain(void) const
// {
// 	for (int i = 0; i < 4; i++)
// 		std::cout << this->ideas[i] << std::endl;
// }

// void	Brain::setbrain(std::string ideas)
// {
// 	for (int i = 0; i < 100; i++)
// 		this->ideas[i] = std::to_string(i) + "- " + ideas;
// }

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}


