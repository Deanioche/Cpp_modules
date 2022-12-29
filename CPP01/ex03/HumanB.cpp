#include "HumanB.h"
#include <iostream>

HumanB::HumanB(const std::string name) : humanName(name), humanWeapon(NULL) {}

HumanB::~HumanB(void){};

void HumanB::setWeapon(Weapon& ptrWeapon) 
{ 
	this->humanWeapon = &ptrWeapon;
}

void HumanB::attack(void) const
{
	if (humanWeapon == NULL)
		return ;
	std::cout << this->humanName << " attacks with their " << this->humanWeapon->getType() << std::endl;
}
