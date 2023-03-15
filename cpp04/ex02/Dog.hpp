#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public Animal
{
	private:
		Brain *br;
	public:
		Dog();
		Dog(const Dog &);
		~Dog();
		Dog	&operator = (const Dog &);
		void	makeSound() const;
		// void	setBrain(std::string);
		// void	getBrain() const;
};

#endif
