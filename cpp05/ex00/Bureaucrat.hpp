#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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
        std::string	getName() const;
		int		getGrade() const;
        void	incGrade();
		void	decGrade();
        class GradeTooHighException : public std::exception
		{
			virtual const char * what () const throw ();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char * what () const throw ();
		};
};

//flux : output stream object where char are inserted
//obj : char to insert

std::ostream	&operator << (std::ostream &flux, const Bureaucrat & obj);



#endif