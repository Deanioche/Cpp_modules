#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    this->_type = "Cat";
    std::cout << "[ Cat ] Default constructer called" << std::endl;
}

Cat::Cat(const Cat &c) : Animal(c)
{
    std::cout << "[ Cat ] Copy constructer called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "[ Cat ] Destructer called" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
    if (this != &c)
        this->_type = c.getType();
    std::cout << "[ Cat ] Assignment Operator called" << std::endl;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "[ Cat ] Meow Meow Meow!" << std::endl;
}
