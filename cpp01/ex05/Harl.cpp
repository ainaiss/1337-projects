#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout   << "DEBUG" << std::endl 
                <<   "I love to get extra bacon for my " 
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I just love it!" << std::endl;
}

void	Harl::info( void )
{
	std::cout   << "INFO" << std::endl
                << "I cannot believe adding extra bacon cost more money. "
				<< "You don’t put enough!"
				<< " If you did I would not have to asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout   << "WARNING" << std::endl
                << "I think I deserve to have some extra bacon for free."
				<< " I’ve been coming here for years and you just started"
				<< " working here last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout   << "ERROR" << std::endl
                << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string	str[] = {"debug", "info", "warning", "error"};
     //declare pmf as pointer to A member function,
        // taking no args and returning void
	void	(Harl:: *pmf[]) (void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	for (int i = 0; i < 4; i++)
		if (str[i] == level)
        // call the member function pointed to by pmf points on this object
        //calls Harl::functions on this object
			(this->*pmf[i])();
}