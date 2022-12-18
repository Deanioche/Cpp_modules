#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H
#include <string>
#include <iostream>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	~Zombie();

	void announce( void ) const;
	void setName(std::string& name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
