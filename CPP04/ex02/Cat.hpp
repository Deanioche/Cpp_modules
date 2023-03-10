#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;
public:
    Cat(void);
    Cat(const Cat &c);
    virtual ~Cat(void);
    Cat &operator=(const Cat &c);

    Brain *getBrain(void) const;

    void makeSound(void) const;
};

#endif
