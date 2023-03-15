#include "Contact.hpp"

Contact::Contact(){

} 

Contact::~Contact(){

} 

//getter

string	Contact::get_First_name() const
{
	return (this->_first_name);
}

string Contact::get_Last_name() const
{
    return (this->_last_name);
}

string Contact::get_Nickname() const
{
    return (this->_nickname);
}

string Contact::get_Phone_number() const
{
    return (this->_phone_number);
}

string Contact::get_Darkest_secret() const
{
    return (this->_darkest_secret);
}

//setter

void	Contact::set_First_name(string	first_name)
{
	this->_first_name = first_name;
}

void	Contact::set_Last_name(string	last_name)
{
	this->_last_name = last_name;
}

void	Contact::set_Nickname(string	nickname)
{
	this->_nickname = nickname;
}

void	Contact::set_Phone_number(string	phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::set_Darkest_secret(string	darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

void Contact::addContact()
{
	std::cout << "add first name: ";
	getline(std::cin, _first_name);
	std::cout << "add last name: ";
	getline(std::cin, _last_name);
	std::cout  << "add nickname: ";
	getline(std::cin, _nickname);
	std::cout << "add phone number: ";
	getline(std::cin, _phone_number);
	std::cout << "add darkest secret: ";
	getline(std::cin, _darkest_secret);
}

bool Contact::isEmpty() const
{
	if (!this->_first_name.length() || !this->_last_name.length() || !this->_nickname.length() || !this->_phone_number.length() || !this->_darkest_secret.length())
		return true;
	return false;
}