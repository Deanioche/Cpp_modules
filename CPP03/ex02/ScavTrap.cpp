#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Scav_default", 100, 50, 20)
{
	std::cout << "[ScavTrap] " << this->_name << " : Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "[ScavTrap] " << this->_name << " : Constructor with name called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap) : ClapTrap(scavtrap)
{
	std::cout << "[ScavTrap] " << this->_name << " : Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap] " << this->_name << " : Destructor called" << std::endl;
}

const ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
	if (this != &scavTrap)
	{
		this->_name = scavTrap._name;
		this->_hitPoints = scavTrap._hitPoints;
		this->_energyPoints = scavTrap._energyPoints;
		this->_attackDamage = scavTrap._attackDamage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		std::cout << "[ScavTrap] " << this->_name << " can't attack : has 0 hit point" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "[ScavTrap] " << this->_name << " can't attack : lack of energy" << std::endl;
	else {
		_energyPoints--;
		std::cout << "[ScavTrap] " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate(void) const
{
	if (_hitPoints == 0)
		std::cout << "[ScavTrap] " << this->_name << " can't be in Gate keeper mode : has 0 hit point" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "[ScavTrap] " << this->_name << " can't be in Gate keeper mode : lack of energy" << std::endl;
	else
		std::cout << "[ScavTrap] " << this->_name << " : I'm now in Gate keeper mode" << std::endl;
}
