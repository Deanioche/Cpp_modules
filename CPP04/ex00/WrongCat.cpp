#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "[ WrongCat ] Default constructer called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wc) : WrongAnimal(wc)
{
    std::cout << "[ WrongCat ] Copy constructer called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "[ WrongCat ] Destructer called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wc)
{
    if (this != &wc)
        this->type = wc.getType();
    std::cout << "[ WrongCat ] Assignment Operator called" << std::endl;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "[ WrongCat ] Myahow Myahow Myahow!" << std::endl;
}
