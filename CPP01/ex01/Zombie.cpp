#include "Zombie.h"

Zombie::Zombie(void) : zombie_name("_defaultName") {}

Zombie::~Zombie(void)
{
	std::cout << "[Destructor] destruction of " << this->zombie_name << std::endl;
}

void Zombie::setName(std::string name) 
{
	this->zombie_name = name;
}

void Zombie::announce(void) const
{
	std::cout << this->zombie_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
