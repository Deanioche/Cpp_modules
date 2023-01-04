#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "[ Brain ] Default constructor" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain &b)
{
	std::cout << "[ Brain ] Copy constructor" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = b.getIdea(i);
}

Brain::~Brain(void)
{
	std::cout << "[ Brain ] Default destructor" << std::endl;
}

Brain &Brain::operator=(const Brain &b)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = b.ideas[i];
	}
	std::cout << "Brain Copy assignment operator called" << std::endl;
	return (*this);
}

std::string Brain::getIdea(int idx) const
{
	if (idx > 99 || idx < 0)
	{
		std::cout << "Error : out of bound (0 ~ 99)" << std::endl;
		return ("");
	}
	return (ideas[idx]);
}

void Brain::setIdea(int idx, std::string idea)
{
	if (idx > 99 || idx < 0)
	{
		std::cout << "Error : out of bound (0 ~ 99)" << std::endl;
		return ;
	}
	ideas[idx] = idea;
}