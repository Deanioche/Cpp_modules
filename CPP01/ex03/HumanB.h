#ifndef HUMAN_B_H
#define HUMAN_B_H
#include <iostream>
#include "Weapon.h"

class HumanB
{
private:
	Weapon *human_weapon;
	std::string human_name;

public:
	HumanB(const std::string name);
	void attack(void) const;
	void setWeapon(Weapon& ptrWeapon);
};

#endif
