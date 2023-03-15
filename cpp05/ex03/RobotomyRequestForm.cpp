#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotoMy Request", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotoMy Request", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj): Form(obj.getName(), 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &)
{
	return *this;
}

void	RobotomyRequestForm::Action() const
{
	if (time(NULL) % 2)
		std::cout << this->getTarget() << " has been robotomized successfully "  << std::endl;
	else
		std::cout << this->getTarget() << " has been failed "  << std::endl;
}
