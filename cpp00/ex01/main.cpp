
#include "PhoneBook.hpp"

void display()
{
	std::cout << "*----------------PHONEBOOK----------------*" << std::endl;
	std::cout << "|                  1-ADD                  |" << std::endl;
	std::cout << "|                 2-SEARCH                |" << std::endl;
	std::cout << "|                  3-EXIT                 |" << std::endl;
	std::cout << "*-----------------------------------------*" << std::endl;
}

int main()
{
	Phonebook phone;
	std::string command;
	
	display();
	while (true)
	{
		std::cout << "> ";
		getline(std::cin, command);
		if (std::cin.fail())
			break;
		if (command == "ADD")
			phone.add();
		else if (command == "SEARCH")
			phone.search();
		else if (command == "EXIT")
		{
			std::cout << " BYE !\n";
			break;
		}
		else
			std::cout << "COMMAND NOT FOUND !\n";
	}
	return (0);
}
