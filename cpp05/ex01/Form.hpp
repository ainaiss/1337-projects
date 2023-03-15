#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _executeGrade;
public:
	Form();
	Form(std::string, int, int);
	Form(const Form &);
	~Form();
	Form &operator=(const Form &);
	std::string getName() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	bool getSigned() const;
	void beSigned(Bureaucrat &);
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &flux, const Form &obj);

#endif
