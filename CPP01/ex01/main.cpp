#include "Zombie.h"

int main(void)
{
	int N = 5;

	// N크기의 좀비 클래스 배열 생성, 모두 Mani 라고 이름 짓는다.
	Zombie *horde = zombieHorde(N, "Mani");

	for (int i = 0; i < N; i++)
		horde[i].announce();

	// new[] 는 delete[]로 할당 해제
	delete[] horde;
	return (0);
}
