#include "HumanA.h"

HumanA::HumanA(const std::string _name, Weapon& _weapon) : name(_name), weapon(_weapon) {}

void HumanA::setWeapon(Weapon& refWeapon) 
{ 
	this->weapon = refWeapon; 
}

void HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
