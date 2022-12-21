#include "HumanB.h"

HumanB::HumanB(const std::string& _name) : name(_name)
{
	this->weapon = nullptr;
}

void HumanB::setWeapon(Weapon& ptrWeapon) 
{ 
	this->weapon = &ptrWeapon; 
}

void HumanB::attack() const
{
	if (weapon == nullptr)
		return ;
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
