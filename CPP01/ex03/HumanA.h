#ifndef HUMAN_A_H
#define HUMAN_A_H
#include <iostream>
#include "Weapon.h"

class HumanA
{
private:
	Weapon& weapon;
	std::string name;

public:
	HumanA(const std::string _name, Weapon& _weapon);
	void attack(void) const;
};

#endif
