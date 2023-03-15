#include "PhoneBook.hpp"

Phonebook::Phonebook(){
    _index = 0;
}

Phonebook::~Phonebook(){}

string	width(string str)
{
	if (str.length() > 10)
	{
		str.erase(str.begin() + 9, str.end());
		str.append(".");
	}
	return (str);
}

void	Phonebook::display_contact()
{
	std::cout
	<< "|" << std::setw(10) << "INDEX" 
	<< "|" << std::setw(10) << "FIRST NAME"
	<< "|" << std::setw(10) << "LAST NAME"
	<< "|" << std::setw(10) << "NICKNAME"
	<< "|" << std::endl;


	for (int i = 0; i < MAX_CONTACT  && !this->_contact[i].isEmpty(); i++)
	{
		std::cout
		<< "|" << std::setw(10) << i + 1
		<< "|" << std::setw(10) << width(this->_contact[i].get_First_name())
		<< "|" << std::setw(10) << width(this->_contact[i].get_Last_name())
		<< "|" << std::setw(10) << width(this->_contact[i].get_Nickname())
		<< "|" << std::endl;
	}
}

void	Phonebook::add()
{
	Contact contact;

	contact.addContact();

	if (contact.isEmpty())
	{
		std::cerr << "Contact can't have any empty field!" << std::endl;
		return ;
	}
	this->_contact[this->_index % MAX_CONTACT] = contact;
	this->_index++;
}

void	Phonebook::search()
{

	unsigned int index;
	this->display_contact();
	std::cout << "Enter The index: ";
	std::cin >> index;
	if (std::cin.fail())
		std::cout<< "INDEX INVALID !\n";
	else
	{
		if (index >= 0 ||index < MAX_CONTACT)
		{
			index--;
			std::cout << "First Name: " << this->_contact[index].get_First_name() << std::endl;
			std::cout << "Last Name: " << this->_contact[index].get_Last_name() << std::endl;
			std::cout << "NickeName: " << this->_contact[index].get_Nickname() << std::endl;
			std::cout << "Phone Number: " << this->_contact[index].get_Phone_number() << std::endl;
			std::cout << "Darkest Secret: " << this->_contact[index].get_Darkest_secret() << std::endl;
		}
		else
			std::cout<< "INDEX INVALID !\n";
	}
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}