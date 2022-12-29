#include "Zombie.h"

Zombie::Zombie(std::string name) : zombieName(name){}

Zombie::~Zombie(void)
{
	std::cout << "[Destructor] destruction of " << zombieName << std::endl;
}

void Zombie::announce(void)
{
	std::cout << zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

