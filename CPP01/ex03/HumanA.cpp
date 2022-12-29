#include "HumanA.h"
#include <iostream>

HumanA::HumanA(const std::string name, Weapon& weapon) : humanName(name), humanWeapon(weapon) {}

HumanA::~HumanA(void){};

void HumanA::attack(void) const
{
	std::cout << this->humanName << " attacks with their " << this->humanWeapon.getType() << std::endl;
}
