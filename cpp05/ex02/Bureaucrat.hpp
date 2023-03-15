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
		~Bureaucrat() {} ;
		Bureaucrat	&operator = (const Bureaucrat &);
		void		incGrade();
		void		decGrade();
		std::string	getName() const;
		int			getGrade() const;
		void		signForm(Form &);
		void		executeForm(Form const & form);
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