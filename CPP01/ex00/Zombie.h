#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H
#include <string>
#include <iostream>

class Zombie
{
private:
	std::string zombie_name;
public:
	Zombie(const std::string& name);
	~Zombie();
	void announce( void ) const;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
