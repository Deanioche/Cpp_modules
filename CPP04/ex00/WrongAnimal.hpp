#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &wa);
	~WrongAnimal(void);

	std::string getType(void) const;
	void setType(const std::string &type);
	void makeSound(void) const;
};

std::ostream &operator<<(std::ostream &o, const WrongAnimal &wa);

#endif