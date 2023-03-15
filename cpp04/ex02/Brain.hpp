#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain &br);
		~Brain();
		Brain &operator = (const Brain &);
		const std::string *getbrain(void) const;
		void	setbrain(std::string);
};

#endif