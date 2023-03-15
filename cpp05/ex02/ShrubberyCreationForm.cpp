#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shrubbery Creation", 145, 137)
{
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj): Form(obj.getName(), 145, 137)
{
	*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm	const &obj)
{
	(void)obj;
	return *this;
}

void	ShrubberyCreationForm::Action() const
{
	std::ofstream	file(this->getTarget() + "_shrubbery");
	file	<< "         v"				<< std::endl
			<< "        >X<"			<< std::endl
			<< "         A"				<< std::endl
			<< "        d$b"			<< std::endl
			<< "      .d\\$$b."			<< std::endl
			<< "    .d$i$$\\$$b."		<< std::endl
			<< "       d$$@b"			<< std::endl
			<< "      d\\$$$ib"			<< std::endl
			<< "    .d$$$\\$$$b"		<< std::endl
			<< "  .d$$@$$$$\\$$ib."		<< std::endl
			<< "      d$$i$$b"			<< std::endl
			<< "     d\\$$$$@$b"		<< std::endl
			<< "  .d$@$$\\$$$$$@b."		<< std::endl
			<< ".d$$$$i$$$\\$$$$$$b."	<< std::endl
			<< "        ###" 			<< std::endl
			<< "        ###" 			<< std::endl
			<< "        ###" 			<< std::endl;
	file.close();
}
