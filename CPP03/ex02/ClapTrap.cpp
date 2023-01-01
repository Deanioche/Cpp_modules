#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Clap_default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "[ClapTrap] " << this->_name << " : Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "[ClapTrap] " << this->_name << " : Constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "[ClapTrap] " << this->_name << " :  Constructor with all attributes called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "[ClapTrap] " << this->_name << " : Copy constructor called" << std::endl;
	(*this) = claptrap;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ClapTrap] " << this->_name << " : Destructor called" << std::endl;
}

// c++의 private 속성은 class 기준이지, instance 기준이 아니므로, 같은 클래스이면 다른 인스턴스의 private 멤버에도 접근할 수 있다.
const ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
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
	if (_hitPoints == 0)
		std::cout << "[ClapTrap] " << this->_name << " can't attack : no hit point" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "[ClapTrap] " << this->_name << " can't attack : lack of energy" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "[ClapTrap] " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << "[ClapTrap] " << this->_name << " can't take damage : no hit point" << std::endl;
	else
	{
		if (_hitPoints < amount)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
		std::cout << "[ClapTrap] " << this->_name << " take damage. Total hit point is " << this->_hitPoints << "" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << "[ClapTrap] " << this->_name << " can't be repaired : no hit point" << std::endl;
	else if (_energyPoints == 0)
	{
		std::cout << "[ClapTrap] " << this->_name << " can't be repaired : lack of energy" << std::endl;
	}
	else
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "[ClapTrap] " << this->_name << " is repaired. Total hit point is " << this->_hitPoints << "" << std::endl;
	}
}
