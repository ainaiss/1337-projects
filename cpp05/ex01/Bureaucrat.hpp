#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string, int grade);
		Bureaucrat(const Bureaucrat &);
		~Bureaucrat();
		Bureaucrat	&operator = (const Bureaucrat &);
		std::string	getName() const;
		int		getGrade() const;
		void	incGrade();
		void	decGrade();
		void	signForm(Form &);
		class GradeTooHighException : public std::exception
		{
			const char * what () const throw ();
		};
		class GradeTooLowException : public std::exception
		{
			const char * what () const throw ();
		};
};

std::ostream	&operator << (std::ostream &flux, const Bureaucrat & obj);
#endif