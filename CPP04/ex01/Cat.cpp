#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal()
{
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "[ Cat ] Default constructer called" << std::endl;
}

Cat::Cat(const Cat &c)
{
    this->_type = c.getType();
	this->_brain = new Brain();
	*(this->_brain) = *(c.getBrain());
    std::cout << "[ Cat ] Copy constructer called" << std::endl;
}

Cat::~Cat(void)
{
    delete this->_brain;
    std::cout << "[ Cat ] Destructer called" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
        if (this != &c)
    {
        this->_type = c.getType();
        delete this->_brain;
		this->_brain = new Brain();
		*(this->_brain) = *(c.getBrain());
    }
    std::cout << "[ Cat ] Assignment Operator called" << std::endl;
    return (*this);
}

Brain *Cat::getBrain(void) const
{
	return (this->_brain);
}

void Cat::makeSound(void) const
{
    std::cout << "[ Cat ] Meow Meow Meow!" << std::endl;
}
