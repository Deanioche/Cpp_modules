#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap parent("Parent");
	ScavTrap boy("Boy");
	FragTrap girl("Girl");
	std::cout << std::endl;

	parent.attack("Girl");
	girl.takeDamage(0);
	girl.attack("Boy");
	boy.takeDamage(30);
	boy.attack("Girl");
	girl.takeDamage(20);
	std::cout << std::endl;

	girl.highFivesGuys();
	std::cout << std::endl;

	girl.beRepaired(1000);
	girl.takeDamage(1000);
	girl.attack("Parent");
	parent.takeDamage(30);
	girl.attack("Boy");
	boy.takeDamage(30);
	girl.attack("Boy");
	boy.takeDamage(30);
	std::cout << std::endl;

	girl.highFivesGuys();
	boy.guardGate();
	std::cout << std::endl;

	girl.attack("Boy");
	boy.takeDamage(30);
	girl.attack("Boy");
	boy.takeDamage(30);
	std::cout << std::endl;

	girl.takeDamage(1000);
	girl.attack("Parent");
	girl.takeDamage(20);
	girl.beRepaired(20);
	girl.highFivesGuys();
	std::cout << std::endl;

	/*
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
	*/
	return (0);
}
