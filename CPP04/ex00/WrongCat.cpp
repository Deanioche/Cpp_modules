// Copyright @bigpel66

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    _type = "WrongCat";
    std::cout << "[ WrongCat ] Default constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wc) : WrongAnimal(wc)
{
    std::cout << "[ WrongCat ] Copy constructed" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "[ WrongCat ] Destructed " << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wc)
{
    if (this != &wc)
        _type = wc.getType();
    std::cout << "[ WrongCat ] Assigned" << std::endl;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "[ WrongCat ] Myahow Myahow Myahow!" << std::endl;
}
