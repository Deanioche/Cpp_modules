#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
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
        this->_type = wa.getType();
    std::cout << "[ WrongAnimal ] Assignment operator called" << std::endl;
    return (*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "[ WrongAnimal ] (Silence)" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}

void WrongAnimal::setType(const std::string &type)
{
    this->_type = type;
}

std::ostream &operator<<(std::ostream &os, const WrongAnimal &wa)
{
    return os << wa.getType() << " ";
}

