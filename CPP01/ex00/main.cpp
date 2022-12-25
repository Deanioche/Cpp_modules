#include "Zombie.h"

int main(void)
{	
	// 함수가 실행되면, Zombie 클래스를 스택 메모리에 생성후 출력한 뒤, 함수가 종료되면 함께 메모리상에서 소멸된다.
	randomChump(std::string("Unknown_body"));

	// 힙 메모리에 생성하기
	// 필요한 특정 순간에만 쓰기 위해.
	// newZombie 함수는 new 키워드를 이용해 클래스의 인스턴스를 메모리에 할당한 뒤, 포인터주소를 반환.
	Zombie *heap_zomb = newZombie(std::string("Your_heap"));
	heap_zomb->announce();
	delete heap_zomb;	// 필요가 없어졌으므로 제거.

	// 스택 메모리에 생성
	// 프로그램이 동작하는 동안 사용
	Zombie push_swap_zomb(std::string("Push_swap"));
	push_swap_zomb.~Zombie();
	push_swap_zomb.announce();
}
