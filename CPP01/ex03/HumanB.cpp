#include "HumanB.h"

HumanB::HumanB(const std::string name) : human_name(name)
{
	this->human_weapon = NULL;
}

void HumanB::setWeapon(Weapon& ptrWeapon) 
{ 
	this->human_weapon = &ptrWeapon;
}

void HumanB::attack(void) const
{
	if (human_weapon == NULL)
		return ;
	std::cout << this->human_name << " attacks with their " << this->human_weapon->getType() << std::endl;
}
