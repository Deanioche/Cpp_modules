#ifndef HUMAN_B_H
#define HUMAN_B_H
#include <iostream>
#include "Weapon.h"

class HumanB
{
private:
	Weapon *weapon;
	std::string name;

public:
	HumanB(const std::string _name);
	void attack(void) const;
	void setWeapon(Weapon& ptrWeapon);
};

#endif
