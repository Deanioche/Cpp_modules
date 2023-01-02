#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Frag_default", 100, 100, 30)
{
	std::cout << "[FragTrap] " << this->_name << " : Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "[FragTrap] " << this->_name << " : Constructor with name called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap(fragTrap)
{
	std::cout << "[FragTrap] " << this->_name << " : Copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap] " << this->_name << " : Destructor called" << std::endl;
}

const FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
	if (this != &fragTrap)
	{
		this->_name = fragTrap._name;
		this->_hitPoints = fragTrap._hitPoints;
		this->_energyPoints = fragTrap._energyPoints;
		this->_attackDamage = fragTrap._attackDamage;
	}
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout << "[FragTrap] " << this->_name << " can't attack : has 0 hit point" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "[FragTrap] " << this->_name << " can't attack : has 0 energy" << std::endl;
	else {
		this->_energyPoints--;
		std::cout << "[FragTrap] " << this->_name << " kicked " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
		std::cout << "[FragTrap] " << this->_name << " can't request high fives : has 0 hit point" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "[FragTrap] " << this->_name << " can't request high fives : has 0 energy" << std::endl;
	else
		std::cout << "[FragTrap] " << this->_name << " : high five!" << std::endl;
}
