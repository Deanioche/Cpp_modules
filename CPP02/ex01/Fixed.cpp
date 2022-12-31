#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _fixed_point(0)
{
	std::cout << "\033[0;33mDefault Constructor called of Fixed\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "\033[0;33mCopy Constructor called of Fixed\033[0m" << std::endl;
	*this = copy;
}

Fixed::Fixed( int const n ) : _fixed_point( n << _fractionalBits )
{
	std::cout << "\033[0;33mInt constructor called.\033[0m" << std::endl;
	return ;
}

Fixed::Fixed( float const f ) : _fixed_point( roundf(f * (1 << _fractionalBits)) )
{
	std::cout << "\033[0;33mFloat constructor called.\033[0m" << std::endl;
	return ;
}


// Destructor
Fixed::~Fixed(void)
{
	std::cout << "\033[0;31mDestructor called of Fixed\033[0m" << std::endl;
}


// Operator =
Fixed & Fixed::operator=(const Fixed &assign)
{
	std::cout << "\033[0;32mCopy assignment operator called.\033[0m" << std::endl;
	if (this != &assign)
		this->_fixed_point = assign.getRawBits();
	return (*this);
}


// Getters / Setters
int Fixed::getRawBits(void) const 
{
	std::cout << "\033[0;36mgetRawBits member function called\033[0m" << std::endl;
	return (this->_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "\033[0;setRawBits member funtion called.\033[0m" << std::endl;
	this->_fixed_point = raw;
	return ;
}


// Public Functions
int Fixed::toInt(void) const
{
	return (this->_fixed_point >> Fixed::_fractionalBits);	
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixed_point) / (1 << Fixed::_fractionalBits));
}


// Operator <<
std::ostream& operator<<( std::ostream& os, const Fixed& number )
{
	return (os << number.toFloat());
}
