#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Frag_default", 100, 100, 30)
{
	std::cout << "[FragTrap] " << this->_name << " : Default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "[FragTrap] " << this->_name << " : Constructor with name called\n";
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap(fragTrap)
{
	std::cout << "[FragTrap] " << this->_name << " : Copy constructor called\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap] " << this->_name << " : Destructor called\n";
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
	if (_hitPoints == 0)
		std::cout << "[FragTrap] " << this->_name << " can't attack : discharged\n";
	else if (_energyPoints == 0)
		std::cout << "[FragTrap] " << this->_name << " can't attack : lack of energy\n";
	else {
		_energyPoints--;
		std::cout << "[FragTrap] " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
	}
}

void FragTrap::highFivesGuys(void)
{
	if (_hitPoints == 0)
		std::cout << "[FragTrap] " << this->_name << " can't request high fives : discharged\n";
	else if (_energyPoints == 0)
		std::cout << "[FragTrap] " << this->_name << " can't request high fives : lack of energy\n";
	else
		std::cout << "[FragTrap] " << this->_name << " : Let's high fives guys !\n";
}
