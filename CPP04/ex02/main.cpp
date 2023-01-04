#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define BLUE "\x1b[34;1m"
#define RESET "\x1b[0m"

int main(void)
{
    std::cout << BLUE << "----------- Basic Test -----------" << RESET << std::endl;
	{
		//const Animal *a = new Animal();
		const Animal *d = new Dog();
		const Animal *c = new Cat();
		std::cout << std::endl;

		std::cout << d->getType() << std::endl;
		std::cout << c->getType() << std::endl;
		std::cout << std::endl;

		d->makeSound();
		c->makeSound();
		std::cout << std::endl;

		delete d;
		delete c;
	}
	return (0);
}