#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "---->Tests 1<----" << std::endl;
	try
	{
		Intern ahmed;
		Form *task;
		task = ahmed.makeForm("RobotoMy Request", "Pardon");
		std::cout << task->getName() << std::endl;
	
		delete task;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---->Tests 2<----" << std::endl;

	try
	{
		Intern ahmed;
		Form *task;
		task = ahmed.makeForm("Shrubbery Creation", "home");
		std::cout << task->getName() << std::endl;
		delete task;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---->Tests 3<----" << std::endl;

	try
	{
		Intern ahmed;
		Form *task;
		task = ahmed.makeForm("Presidential Pardon", "PARDON");
		std::cout << task->getName() << std::endl;
		delete task;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---->Tests 3<----" << std::endl;

	try
	{
		Intern ahmed;
		Form *task;
		task = ahmed.makeForm("RbotMyRequest", "error");
		std::cout << task->getName() << std::endl;
		delete task;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}