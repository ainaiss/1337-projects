
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string);
		ScavTrap(const ScavTrap &);
		~ScavTrap();
		ScavTrap &operator = (ScavTrap const &);
		void attack(const std::string &);
		void guardGate();
};

