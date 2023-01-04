#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
    std::cout << "[ Brain ] Default constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "";
}

Brain::Brain(const Brain &b)
{
    std::cout << "[ Brain ] Copy constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = b.getIdea(i);
}

Brain::~Brain(void)
{
    std::cout << "[ Brain ] Default destructor" << std::endl;
}

Brain &Brain::operator=(const Brain &b)
{
    if (this != &b)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = b._ideas[i];
    }
    std::cout << "[ Brain ] Assignment operator called" << std::endl;
    return (*this);
}

std::string Brain::getIdea(int idx) const
{
    if (idx > 99 || idx < 0)
    {
        std::cout << "Error : Out of bound (0 ~ 99)" << std::endl;
        return ("");
    }
    return (this->_ideas[idx]);
}

void Brain::setIdea(int idx, std::string idea)
{
    if (idx > 99 || idx < 0)
    {
        std::cout << "Error : Out of bound (0 ~ 99)" << std::endl;
        return ;
    }
    this->_ideas[idx] = idea;
}