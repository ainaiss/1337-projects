#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon", 25, 5)
{
	this->setTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &)
{
	return *this;
}

void	PresidentialPardonForm::Action() const
{
	std::cout << this->getTarget() << " has been pardoned  by Zafod Beeblebrox" << std::endl;
}
