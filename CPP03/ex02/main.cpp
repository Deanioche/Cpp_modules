#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Clap");
	ScavTrap scavtrap("Scav");
	FragTrap fragtrap("Frag");
	std::cout << std::endl;

	fragtrap.attack("Scav");
	claptrap.attack("Scav");
	scavtrap.attack("Clap");
	std::cout << std::endl;

	fragtrap.attack("Scav");
	fragtrap.attack("Scav");
	fragtrap.attack("Scav");
	fragtrap.attack("Scav");
	std::cout << std::endl;

	fragtrap.highFivesGuys();
	std::cout << std::endl;

	fragtrap.beRepaired(18);

	fragtrap.takeDamage(50);

	fragtrap.takeDamage(500);

	fragtrap.beRepaired(20);
	fragtrap.attack("Scav");

	std::cout << std::endl;
	return (0);
}