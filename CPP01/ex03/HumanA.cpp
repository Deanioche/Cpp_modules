#include "HumanA.h"
#include <iostream>

HumanA::HumanA(const std::string name, Weapon& weapon) : human_name(name), human_weapon(weapon) {}

HumanA::~HumanA(void){};

void HumanA::attack(void) const
{
	std::cout << this->human_name << " attacks with their " << this->human_weapon.getType() << std::endl;
}
