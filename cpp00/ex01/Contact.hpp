#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

using std::string;

class Contact
{
    private:
       	std::string  _first_name;
        std::string	_last_name;
	    std::string	_nickname;
	   	std::string	_phone_number;
	    std::string	_darkest_secret;
    public:
        Contact();
        ~Contact();
        std::string		get_First_name() const;
	    std::string		get_Last_name() const;
	    std::string		get_Nickname() const;
	    std::string		get_Phone_number() const;
	    std::string		get_Darkest_secret() const;

        void		set_First_name(std::string first_name);
	    void		set_Last_name(std::string last_name);
	    void		set_Nickname(std::string Nickname);
	    void		set_Phone_number(std::string Phone_number);
	    void		set_Darkest_secret(std::string Darkest_secret);
		void 		addContact();
		bool        isEmpty() const;

};

#endif
