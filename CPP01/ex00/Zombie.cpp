#include "Zombie.h"

// 생성자
// 파라미터로 받은 name이 멤버변수 zombie_name에 담긴다.
Zombie::Zombie(const std::string name) : zombie_name(name){}

Zombie::~Zombie()
{
	std::cout << "[Destructor] destruction of " << zombie_name << std::endl;
}

void Zombie::announce() const
{
	std::cout << zombie_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

