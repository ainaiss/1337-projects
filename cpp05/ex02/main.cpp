#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Form *n = new ShrubberyCreationForm("Form-Home");
		Bureaucrat b("ME1", 15);
		b.signForm(*n);
		b.executeForm(*n);
		delete n;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------" << std::endl;

	try
	{
		Bureaucrat b("ME2", -40);
		Form *n = new RobotomyRequestForm("Robot");

		b.signForm(*n);
		b.executeForm(*n);
		delete n;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------" << std::endl;

	try
	{
		Bureaucrat b("ME3", 5);
		Form *n = new PresidentialPardonForm("president");

		b.signForm(*n);
		b.executeForm(*n);
		delete n;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------" << std::endl;

	try
	{
		Bureaucrat b("ME4", 149);
		Form *n = new ShrubberyCreationForm("home");
		b.signForm(*n);
		b.executeForm(*n);
		delete n;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
