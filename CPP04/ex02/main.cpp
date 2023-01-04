#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define BLUE "\x1b[34;1m"
#define GREEN "\x1b[0;32m"
#define RESET "\x1b[0m"

int main(void)
{
    // Basic Test
    std::cout << BLUE << "----------- Basic Test -----------" << RESET << std::endl;
    {
		// const Animal *a = new Animal();
        const Animal *j = new Dog();
        std::cout << std::endl;

        const Animal *i = new Cat();
        std::cout << std::endl;

        delete j; //should not create a leak
        std::cout << std::endl;

        delete i;
        std::cout << std::endl;
    }

    std::cout << BLUE << "---------- Deep Copy Test --------" << RESET 
                << std::endl
                << std::endl;
    {
        std::cout << GREEN << "--- TEST Dog ---" << RESET << std::endl;

        Dog D1;
        D1.getBrain()->setIdea(0, "Hungry...");
        std::cout << GREEN << "-" << RESET << std::endl;

        Dog D2(D1);
        std::cout << GREEN << "-" << RESET << std::endl;

        Dog D3;
        std::cout << std::endl;
        D3 = D1;
        std::cout << std::endl;

        std::cout << GREEN << "Before" << RESET << std::endl;
        std::cout << "D1 : " << D1.getBrain()->getIdea(0) << std::endl;
        std::cout << "D2 : " << D2.getBrain()->getIdea(0) << std::endl;
        std::cout << "D3 : " << D3.getBrain()->getIdea(0) << std::endl;
        std::cout << std::endl;

        D1.getBrain()->setIdea(0, "Snack!");

        std::cout << GREEN << "After" << RESET << std::endl;
        std::cout << "D1 : " << D1.getBrain()->getIdea(0) << std::endl;
        std::cout << "D2 : " << D2.getBrain()->getIdea(0) << std::endl;
        std::cout << "D3 : " << D3.getBrain()->getIdea(0) << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << GREEN << "--- TEST Cat ---" << RESET << std::endl;
        Cat C1;
        C1.getBrain()->setIdea(0, "Meowwwwww");
        std::cout << GREEN << "-" << RESET << std::endl;

        Cat C2(C1);
        std::cout << GREEN << "-" << RESET << std::endl;

        Cat C3;
        std::cout << std::endl;

        C3 = C1;
        std::cout << std::endl;

        std::cout << GREEN << "Before" << RESET << std::endl;
        std::cout << "D1 : " << C1.getBrain()->getIdea(0) << std::endl;
        std::cout << "D2 : " << C2.getBrain()->getIdea(0) << std::endl;
        std::cout << "D3 : " << C3.getBrain()->getIdea(0) << std::endl;
        std::cout << std::endl;

        C1.getBrain()->setIdea(0, "Fish!");

        std::cout << GREEN << "After" << RESET << std::endl;
        std::cout << "C1 : " << C1.getBrain()->getIdea(0) << std::endl;
        std::cout << "C2 : " << C2.getBrain()->getIdea(0) << std::endl;
        std::cout << "C3 : " << C3.getBrain()->getIdea(0) << std::endl;
        std::cout << std::endl;
    }

    // Subject Test
    {
        std::cout << BLUE << "\n--------- Subject Test ----------" << RESET << std::endl;
        Animal *animal[6];
        for (int i = 0; i < 6; i++)
        {
            std::cout << GREEN << i << RESET << std::endl;
            if (i % 2)
                animal[i] = new Dog();
            else
                animal[i] = new Cat();
            std::cout << std::endl;
        }

        for (int i = 0; i < 6; i++)
            animal[i]->makeSound();

        std::cout << std::endl;
        for (int i = 0; i < 6; i++)
            delete animal[i];

    }
    return (0);
}