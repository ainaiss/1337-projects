#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &);
	~RobotomyRequestForm();
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &);
	void 	Action() const;
};
#endif
