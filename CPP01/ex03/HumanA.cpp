#include "HumanA.h"

HumanA::HumanA(const std::string name, Weapon& weapon) : human_name(name), human_weapon(weapon) {}

void HumanA::setWeapon(Weapon& refWeapon) 
{ 
	std::cout << "getW : " << refWeapon.getType() << "\n";
	std::cout << "getHW : " << this->human_weapon.getType() << "\n";
	this->human_weapon = refWeapon;
	std::cout << "getHW : " << this->human_weapon.getType() << "\n";
}

void HumanA::attack(void) const
{
	std::cout << this->human_name << " attacks with their " << this->human_weapon.getType() << std::endl;
}
