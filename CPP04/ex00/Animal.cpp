#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
    std::cout << "[ Animal ] Default constructer called" << std::endl;
}

Animal::Animal(const Animal &a)
{
    if (this != &a)
        (*this) = a;
    std::cout << "[ Animal ] Copy constructer called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "[ Animal ] Destructer called" << std::endl;
}

Animal &Animal::operator=(const Animal &a)
{
    if (this != &a)
        this->type = a.getType();
    std::cout << "[ Animal ] Assignment Operator called" << std::endl;
    return (*this);
}

void Animal::makeSound(void) const
{
    std::cout << "[ Animal ] (Silence)" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void Animal::setType(const std::string &type)
{
    this->type = type;
}
