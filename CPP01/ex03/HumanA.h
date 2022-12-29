#ifndef HUMAN_A_H
#define HUMAN_A_H
#include "Weapon.h"

class HumanA
{
private:
	std::string human_name;
	Weapon& human_weapon;

public:
	HumanA(const std::string name, Weapon& weapon);
	~HumanA(void);
	void attack(void) const;
};

#endif
