#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void test_animal(void)
{
    const Animal *meta = new Animal();
    const Animal *i = new Cat();
    const Animal *j = new Dog();
    std::cout << std::endl;

    meta->makeSound();
    i->makeSound();
    j->makeSound();
    std::cout << std::endl;

    std::cout << meta->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << std::endl;
    delete j;
    delete i;
    delete meta;
}

void test_wrong(void)
{
    const WrongAnimal *meta = new WrongAnimal();
    const WrongAnimal *i = new WrongCat();
    const WrongCat *j = new WrongCat();

    std::cout << std::endl;

    meta->makeSound();
    i->makeSound();
    j->makeSound();
    std::cout << std::endl;

    std::cout << meta->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << std::endl;
    delete j;
    delete i;
    delete meta;
}

int main(void)
{
    std::cout << std::endl;
    std::cout << "# Animal test"
            << std::endl
            << std::endl;

    test_animal();

    std::cout << std::endl
            << std::endl;

    std::cout << "# WrongAnimal test" 
            << std::endl 
            << std::endl;
            
    test_wrong();

    std::cout << std::endl;
    return (0);
}
