#ifndef HUMAN_A_H
#define HUMAN_A_H
#include "Weapon.h"

class HumanA
{
private:
	std::string humanName;
	Weapon& humanWeapon;

public:
	HumanA(const std::string name, Weapon& weapon);
	~HumanA(void);
	void attack(void) const;
};

#endif
