#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form ta("Form", 50, 10);
		Bureaucrat school("school", 55);
		school.signForm(ta);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}
	std::cout << "---------------------------------\n";
	try
	{
		Form ta("Form1", 50, 10);
		Bureaucrat school("school", 49);
		school.signForm(ta);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}
}
