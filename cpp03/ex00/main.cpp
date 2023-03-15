#include "ClapTrap.hpp"

int main()
{
	ClapTrap player0;
    ClapTrap player2("player2");
    ClapTrap player1(player2);

    player1.attack("target");
   player1.takeDamage(30);
    player1.beRepaired(20);
}