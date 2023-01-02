#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap parent("Parent");
	ScavTrap boy("Boy");
	std::cout << std::endl;

	parent.attack("Boy");
	boy.takeDamage(0);
	boy.attack("Parent");
	boy.takeDamage(20);
	std::cout << std::endl;

	boy.guardGate();
	std::cout << std::endl;

	boy.beRepaired(1000);
	boy.takeDamage(1000);
	boy.attack("Parent");
	parent.takeDamage(20);
	std::cout << std::endl;

	parent.attack("Boy");
	parent.beRepaired(100);
	parent.takeDamage(1);
	std::cout << std::endl;

	boy.takeDamage(1000);
	boy.attack("Parent");
	boy.takeDamage(20);
	boy.beRepaired(20);
	boy.guardGate();
	std::cout << std::endl;

	return (0);
}
