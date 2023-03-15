#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string _name;

public:
    Zombie();
    Zombie(std::string);
    ~Zombie();
    std::string get_zombie_name();
    void set_zombie_name(std::string name);
    void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif