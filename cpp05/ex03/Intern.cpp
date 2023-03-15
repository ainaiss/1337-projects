#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &obj)
{
	*this = obj;
}

Intern	&Intern::operator=(Intern const &)
{
	return *this;
}

Intern::~Intern()
{
}

Form	*Intern::President(std::string target)
{
	Form *ret = new PresidentialPardonForm(target);
	std::cout << "Intern creates " << ret->getName() << std::endl;
	return (ret);
}

Form	*Intern::Shrubbery(std::string target)
{
	Form *ret = new ShrubberyCreationForm(target);
	std::cout << "Intern creates " << ret->getName() << std::endl;

	return (ret);
}

Form	*Intern::Robotomy(std::string target)
{
	Form *ret = new RobotomyRequestForm(target);
	std::cout << "Intern creates " << ret->getName() << std::endl;

	return (ret);
}

Form	*Intern::makeForm(std::string nameForm, std::string targetForm)
{
	std::string names[3] = {"Presidential Pardon", "RobotoMy Request", "Shrubbery Creation"};
	typedef	Form*(Intern::*Form)(std::string);
	Form	forms[3] = {&Intern::President, &Intern::Robotomy, &Intern::Shrubbery};
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == nameForm)
			return ((this->*forms[i])(targetForm));
	}
	throw UnknownFormExeception();
}

const	char	*Intern::UnknownFormExeception::what() const throw()
{
	return "Unknown Name Form";
}
