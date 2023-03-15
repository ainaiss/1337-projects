#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj._name), _grade(obj._grade)
{

}

Bureaucrat	&Bureaucrat::operator = (const Bureaucrat &obj)
{
	if (this != &obj)
		this->_grade = obj._grade;
	return *this;
}

void	Bureaucrat::incGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int		Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream	&operator << (std::ostream &flux, const Bureaucrat & obj)
{
	flux << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return flux;
}

const	char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade to High";
}

const	char	*Bureaucrat::GradeTooLowException::what() const throw ()
{
	return "Grade to Low";
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " cannot sign " << form.getName() << " " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}