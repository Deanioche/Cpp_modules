#include "Zombie.h"


Zombie::Zombie() : _name("_defaultName")
{}

Zombie::~Zombie()
{
	std::cout << "[Destructor] destruction of " << _name << std::endl;
}

void Zombie::setName(std::string &name) {_name = name;}

void Zombie::announce() const
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
