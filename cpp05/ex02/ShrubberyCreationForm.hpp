#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	~ShrubberyCreationForm();
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &);
	void	Action() const;
};

#endif