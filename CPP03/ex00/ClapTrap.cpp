#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Clap_default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "[ClapTrap] " << this->_name << " : Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "[ClapTrap] " << this->_name << " : Constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	if (this->_name.empty())
		this->_name = "Clap_default";
	std::cout << "[ClapTrap] " << this->_name << " : Copy constructor called" << std::endl;
	(*this) = claptrap;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ClapTrap] " << this->_name << " : Destructor called" << std::endl;
}

const ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout << "[ClapTrap] " << this->_name << " : Assignment Operator called" << std::endl;
	if (this != &claptrap)
	{
		this->_name = claptrap._name;
		this->_hitPoints = claptrap._hitPoints;
		this->_energyPoints = claptrap._energyPoints;
		this->_attackDamage = claptrap._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
		std::cout << "[ClapTrap] " << this->_name << " can't attack : has 0 hit point" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "[ClapTrap] " << this->_name << " can't attack : has 0 energy" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "[ClapTrap] " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "[ClapTrap] " << this->_name << " can't take " << amount << " damage. : has 0 hit point" << std::endl;
	else
	{
		if (this->_hitPoints < amount)
			this->_hitPoints = 0;
		else
			this->_hitPoints -= amount;
		std::cout << "[ClapTrap] " << this->_name << " take " << amount << " damage. Total hit point is " << this->_hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "[ClapTrap] " << this->_name << " can't be repaired : has 0 hit point" << std::endl;
	else if (this->_energyPoints == 0)
	{
		std::cout << "[ClapTrap] " << this->_name << " can't be repaired : has 0 energy" << std::endl;
	}
	else
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "[ClapTrap] " << this->_name << " is repaired as " << amount << " point. Total hit point is " << this->_hitPoints << std::endl;
	}
}
