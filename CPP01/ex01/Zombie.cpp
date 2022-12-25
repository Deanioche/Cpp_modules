#include "Zombie.h"


Zombie::Zombie(void) : _name("_defaultName") {}

Zombie::~Zombie(void)
{
	std::cout << "[Destructor] destruction of " << _name << std::endl;
}

void Zombie::setName(std::string &name) {_name = name;}

void Zombie::announce(void) const
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
