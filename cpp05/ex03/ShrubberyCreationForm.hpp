#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	class FileNotOpenExeception : std::exception
	{
		const char * what() const throw ();
	};
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &);
	~ShrubberyCreationForm();
	void	Action() const;
};

#endif
