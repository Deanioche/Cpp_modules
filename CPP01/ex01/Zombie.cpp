#include "Zombie.h"

Zombie::Zombie(void) : zombieName("defaultName") {}

Zombie::~Zombie(void)
{
	std::cout << "[Destructor] destruction of " << this->zombieName << std::endl;
}

void Zombie::setName(std::string name) 
{
	this->zombieName = name;
}

void Zombie::announce(void)
{
	std::cout << this->zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
