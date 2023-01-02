#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	f(void)
{
	ClapTrap clapTrap("Parent");
	ScavTrap scavTrap("Kid");
	std::cout << std::endl;

	clapTrap.attack("Kid");
	scavTrap.takeDamage(0);
	scavTrap.attack("Parent");
	scavTrap.takeDamage(20);
	std::cout << std::endl;

	scavTrap.guardGate();
	std::cout << std::endl;

	scavTrap.beRepaired(1000);
	scavTrap.takeDamage(1000);
	scavTrap.attack("Parent");
	clapTrap.takeDamage(20);
	std::cout << std::endl;

	clapTrap.attack("Kid");
	clapTrap.beRepaired(100);
	clapTrap.takeDamage(1);
	std::cout << std::endl;

	scavTrap.takeDamage(1000);
	scavTrap.attack("Parent");
	scavTrap.takeDamage(20);
	scavTrap.beRepaired(20);
	scavTrap.guardGate();
	std::cout << std::endl;

	// scavTrap.attack("Parent");
	// clapTrap.takeDamage(20);
	// scavTrap.attack("Parent");
	// clapTrap.takeDamage(20);
	// scavTrap.attack("Parent");
	// clapTrap.beRepaired(64);
	// std::cout << std::endl;

	// scavTrap.attack("Parent");
	// std::cout << std::endl;

	// scavTrap.takeDamage(100);
	// scavTrap.beRepaired(200);
	// scavTrap.attack("Kid");
	// scavTrap.takeDamage(300);
	// scavTrap.takeDamage(1);
	// scavTrap.beRepaired(1);
	// std::cout << std::endl;

	return (0);
}

#include <string>
#include <unistd.h>
int main(void)
{
	f();
	system(("leaks " + std::to_string(getpid())).c_str());
	return 0;
}