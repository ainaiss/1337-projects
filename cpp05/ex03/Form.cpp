#include "Form.hpp"

Form::Form() : _name(""), _signed(false),_signGrade(0) , _executeGrade(0)
{
}

Form::~Form()
{
}

Form::Form(std::string name, int gradeSign, int gradeExecute) : _name(name), _signed(false) , _signGrade(gradeSign),_executeGrade(gradeExecute)
{
	if (_signGrade < 1)
		GradeTooHighException();
	if (_signGrade > 150)
		GradeTooLowException();
	if (_executeGrade < 1)
		GradeTooHighException();
	if (_executeGrade > 150)
		GradeTooLowException();
}

Form::Form(const Form &obj) : _name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade)
{
}

Form &Form::operator=(const Form &obj)
{
	if (this != &obj)
		this->_signed = obj._signed;
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeExecute() const
{
	return _executeGrade;
}

int Form::getGradeSign() const
{
	return _signGrade;
}

std::ostream &operator<<(std::ostream &flux, const Form &obj)
{
	if (obj.getSigned())
		flux << " Name : " << obj.getName() << " SigneGrade : " << obj.getGradeSign() << " ExecuteGrade : " << obj.getGradeExecute() << " Form is signed\n";
	else
		flux << " Name : " << obj.getName() << " SigneGrade : " << obj.getGradeSign() << " ExecuteGrade : " << obj.getGradeExecute() << " Form is not signed\n";
	return flux;
}

void Form::beSigned(Bureaucrat &bure)
{
	if (bure.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade to High";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade to Low";
}

std::string	Form::getTarget() const
{
	return this->_target;
}

void	Form::setTarget(std::string target)
{
	this->_target = target;
}

const char *Form::FormNotSignedException::what() const throw()
{
	return "Form Not Signed";
}

void	Form::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (this->getGradeExecute() < executor.getGrade())
		throw GradeTooLowException();
	Action();
}
