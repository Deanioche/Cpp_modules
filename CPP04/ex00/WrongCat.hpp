#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat(void);
    WrongCat(const WrongCat &wc);
    ~WrongCat(void);
    WrongCat &operator=(const WrongCat &wc);

    void makeSound(void) const;
};

#endif
