#include "Zombie.h"

// 생성자
// 파라미터로 받은 name이 멤버변수 zombie_name에 담긴다.
Zombie::Zombie(std::string name) : zombieName(name){}

Zombie::~Zombie(void)
{
	std::cout << "[Destructor] destruction of " << zombieName << std::endl;
}

void Zombie::announce(void)
{
	std::cout << zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

