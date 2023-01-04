#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << "[ WrongAnimal ] Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "[ WrongAnimal ] Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
    if (this != &wa)
        (*this) = wa;
    std::cout << "[ WrongAnimal ] Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wa)
{
    if (this != &wa)
        this->type = wa.getType();
    std::cout << "[ WrongAnimal ] Assignment operator called" << std::endl;
    return (*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "[ WrongAnimal ] (Silence)" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void WrongAnimal::setType(const std::string &type)
{
    this->type = type;
}
