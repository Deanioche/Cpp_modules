#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <string>

class Zombie
{
private:
	std::string zombie_name;
public:
	Zombie(const std::string name);
	~Zombie();
	void announce( void ) const;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
