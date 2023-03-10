#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _fixed_point(0)
{
	std::cout << "\033[0;33mDefault Constructor called of Fixed\033[0m" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "\033[0;33mCopy Constructor called of Fixed\033[0m" << std::endl;
	*this = copy;
}

// Destructor
Fixed::~Fixed(void)
{
	std::cout << "\033[0;31mDestructor called of Fixed\033[0m" << std::endl;
}


// Operators
Fixed & Fixed::operator=(Fixed const &assign)
{
	std::cout << "\033[0;32mCopy assignment operator called.\033[0m" << std::endl;
	if (this != &assign)
		this->_fixed_point = assign.getRawBits();
	return (*this);
}


// Getter
int Fixed::getRawBits(void) const 
{
	std::cout << "\033[0;36mgetRawBits member function called\033[0m" << std::endl;
	return (this->_fixed_point);
}


// Setter
void Fixed::setRawBits(int const raw)
{
	std::cout << "\033[0;36msetRawBits member function called\033[0m" << std::endl;
	this->_fixed_point = raw;
}
