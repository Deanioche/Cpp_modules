#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon
{
private:
	std::string type_name;
public:
	Weapon(const std::string type);
	const std::string getType(void) const;
	void setType(const std::string type);
};

#endif
