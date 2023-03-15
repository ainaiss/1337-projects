#include "Bureaucrat.hpp"

int main()
{
	// test the GardeIncrement()
	try
	{
		Bureaucrat me("me", 2);

		std::cout << me << std::endl;
		me.incGrade();
		std::cout << me << std::endl;
		me.incGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << "---------------" << std::endl;
	// test the GardeDecrement()
	try
	{
		Bureaucrat someone("Someone", 149);

		std::cout << someone << std::endl;
		someone.decGrade();
		std::cout << someone << std::endl;
		someone.decGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

     std::cout << "---------------" << std::endl;
	// test the Bureaucrat constructor
	try
	{
		Bureaucrat someone("someone", 999);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat someone("someone", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
