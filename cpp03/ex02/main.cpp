#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

//     	ClapTrap player0;
//     ClapTrap player2("player2");
//     ClapTrap player1(player2);
//     player1.attack("target");
//    player1.takeDamage(30);
//     player1.beRepaired(20);

    std::cout << std::endl
              << std::endl;

    //   ScavTrap S_player0;
    // ScavTrap S_player1("scavtrap");
    // ScavTrap S_player2(S_player1);
    // S_player2.attack("target");
    // S_player2.takeDamage(50);
    // S_player2.beRepaired(40);
    // S_player2.guardGate();

    std::cout << std::endl
              << std::endl;

    FragTrap player0;
    FragTrap player1("FragTrap");
    FragTrap player2(player1);
    player2.attack("target");
    player2.takeDamage(50);
    player2.beRepaired(40);
    player2.highFivesGuys();
}