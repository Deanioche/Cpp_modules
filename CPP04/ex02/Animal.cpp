#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Animal")
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
        this->_type = a.getType();
    std::cout << "[ Animal ] Assignment Operator called" << std::endl;
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->_type);
}

void Animal::setType(const std::string &type)
{
    this->_type = type;
}
