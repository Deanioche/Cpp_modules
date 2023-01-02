#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");
	ClapTrap c(a);
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	b.attack("A");
	a.takeDamage(10);
	a.beRepaired(10);
	a.takeDamage(1);
	a.attack("B");
	std::cout << std::endl;

	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.beRepaired(3);
	std::cout << std::endl;
	
	b.takeDamage(8);
	b.attack("A");
	b.beRepaired(1);
	std::cout << std::endl;
	
	return (0);
}
