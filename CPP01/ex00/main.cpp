#include "Zombie.h"

int main(void)
{	
	randomChump("Unknown_body");

	Zombie *heapZomb = newZombie("Heap_zomb");
	heapZomb->announce();
	delete heapZomb;

	Zombie stackZomb("Stack_zomb");
	stackZomb.announce();
	return (0);
}
