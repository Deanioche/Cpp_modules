#ifndef HUMAN_B_H
#define HUMAN_B_H
#include "Weapon.h"

class HumanB
{
private:
	std::string humanName;
	Weapon *humanWeapon;

public:
	HumanB(const std::string name);
	~HumanB(void);
	void attack(void) const;
	void setWeapon(Weapon& ptrWeapon);
};

#endif
