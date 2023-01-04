#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    _type = "Dog";
    std::cout << "[ Dog ] Default constructer called" << std::endl;
}

Dog::Dog(const Dog &d) : Animal(d)
{
    std::cout << "[ Dog ] Copy constructer called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "[ Dog ] Destructer called" << std::endl;
}

Dog &Dog::operator=(const Dog &d)
{
    if (this != &d)
        _type = d.getType();
    std::cout << "[ Dog ] Assignment Operator called" << std::endl;
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "[ Dog ] Bow Bow Bow!" << std::endl;
}
