#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal(void);
    Animal(const Animal &a);
    virtual ~Animal(void);
    Animal &operator=(const Animal &a);

    std::string getType(void) const;
    void setType(const std::string &type);
    virtual void makeSound(void) const;
};

#endif
