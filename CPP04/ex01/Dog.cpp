#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "[ Dog ] Default constructer called" << std::endl;
}

Dog::Dog(const Dog &d)
{
    this->_type = d.getType();
    this->_brain = new Brain();
    *(this->_brain) = *(d.getBrain());
    std::cout << "[ Dog ] Copy constructer called" << std::endl;
}

Dog::~Dog(void)
{
    delete this->_brain;
    std::cout << "[ Dog ] Destructer called" << std::endl;
}

Dog &Dog::operator=(const Dog &d)
{
    if (this != &d)
    {
        this->_type = d.getType();
        delete this->_brain;
		this->_brain = new Brain();
		*(this->_brain) = *(d.getBrain());
    }
    std::cout << "[ Dog ] Assignment Operator called" << std::endl;
    return (*this);
}

Brain *Dog::getBrain(void) const
{
	return (this->_brain);
}

void Dog::makeSound(void) const
{
    std::cout << "[ Dog ] Bow Bow Bow!" << std::endl;
}
