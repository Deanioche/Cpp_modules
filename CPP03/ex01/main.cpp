#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("A");
	ScavTrap scavtrap("B");
	std::cout << std::endl;

	claptrap.attack("B");
	scavtrap.takeDamage(0);
	scavtrap.beRepaired(18);
	std::cout << std::endl;

	scavtrap.attack("A");
	claptrap.takeDamage(20);
	scavtrap.attack("A");
	claptrap.takeDamage(20);
	scavtrap.attack("A");
	claptrap.beRepaired(64);
	std::cout << std::endl;

	scavtrap.guardGate();
	scavtrap.attack("A");
	std::cout << std::endl;

	scavtrap.takeDamage(100);
	scavtrap.beRepaired(200);
	scavtrap.attack("B");
	scavtrap.takeDamage(300);
	scavtrap.takeDamage(1);
	scavtrap.beRepaired(1);
	std::cout << std::endl;

	return (0);
}
