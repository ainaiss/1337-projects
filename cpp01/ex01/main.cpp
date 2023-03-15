#include "Zombie.hpp"

int main()
{
    Zombie* zom;
    std::string name;
    int number;

    std::cout << "Enter number of zombies /n: " << std::endl;
    std::cin >> number;
    std::cin.ignore();
    if(std::cin.fail())
    {
        std::cout << "wrong input/n";
        return(1);
    }
    std::cout << "name of ur zombies : " << std::endl;
    getline(std::cin, name);
    zom = zombieHorde(number, name);
    delete [] zom;
    return(0);
}