#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

#define MAX_CONTACT 8

class Phonebook
{
    private:
    //attributes
        Contact _contact[MAX_CONTACT];
        int     _index;
    public:
        Phonebook();
        ~Phonebook();

        //methodes can access to private attributes
        void    add();
        void    search();
        void    display_contact();
};

#endif
