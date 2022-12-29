#ifndef HUMAN_A_H
#define HUMAN_A_H
#include <iostream>
#include "Weapon.h"

class HumanA
{
private:
	std::string human_name;
	Weapon& human_weapon;

public:
	HumanA(const std::string name, Weapon& weapon);
	void attack(void) const;
	void setWeapon(Weapon& refWeapon);
};

#endif
