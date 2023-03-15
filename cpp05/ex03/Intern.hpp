#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;

class Intern
{
public:
	Intern();
	Intern(Intern const &);
	Intern	&operator=(Intern const &);
	~Intern();
	Form	*President(std::string);
	Form	*Shrubbery(std::string);
	Form	*Robotomy(std::string);
	Form	*makeForm(std::string, std::string);
	class 	UnknownFormExeception: public std::exception
	{
		virtual const char	* what() const throw();
	};
};

#endif
