#include "Zombie.h"

void randomChump(const std::string name)
{
	Zombie zomb(name);	// 이 함수 안에서만 존재하는 클래스
	zomb.announce();
}
