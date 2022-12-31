#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _fixed_point(0) {}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed( int const n ) : _fixed_point( n << _fractionalBits )
{
	return ;
}

Fixed::Fixed( float const f ) : _fixed_point( roundf(f * (1 << _fractionalBits)) )
{
	return ;
}


// Destructor
Fixed::~Fixed(void) {}


// Operators

/******************************************************************************
 * COMPARISON OPERATORS
 */

// Equal operator
bool Fixed::operator==( Fixed const &f ) const {
	return this->_fixed_point == f.getRawBits();
}

// Not equal operator
bool Fixed::operator!=( Fixed const &f ) const {
	return this->_fixed_point != f.getRawBits();
}

// Greater than operator
bool Fixed::operator>( Fixed const &f ) const {
	return this->_fixed_point > f.getRawBits();
}

// Less than operator
bool Fixed::operator<( Fixed const &f ) const {
	return this->_fixed_point < f.getRawBits();
}

// Greater than or equal operator
bool Fixed::operator>=( Fixed const &f ) const {
	return this->_fixed_point >= f.getRawBits();
}

// Less than or equal operator
bool Fixed::operator<=( Fixed const &f ) const {
	return this->_fixed_point <= f.getRawBits();
}



Fixed Fixed::operator+( const Fixed &f ) const {
	return Fixed(this->toFloat() + f.toFloat());
}

// Substraction operator
Fixed Fixed::operator-( const Fixed &f ) const {
	return Fixed(this->toFloat() - f.toFloat());
}

// Multiplication operator
Fixed Fixed::operator*( const Fixed &f ) const {
	if (this->toFloat() == 0 || f.toFloat() == 0)
		return Fixed(0);
	return Fixed(this->toFloat() * f.toFloat());
}

// Division operator
Fixed Fixed::operator/( const Fixed &f ) const {
	if (f.toFloat() == 0)
		return Fixed(0);
	return Fixed(this->toFloat() / f.toFloat());
}

Fixed & Fixed::operator=(const Fixed &assign)
{
	if (this != &assign)
		this->_fixed_point = assign.getRawBits();
	return (*this);
}

// Increment operator (prefix)
Fixed &Fixed::operator++( void ) {
	this->_fixed_point++;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed tmp(*this);
	this->_fixed_point++;
	return tmp;
}

// Decrement operator (prefix)
Fixed &Fixed::operator--( void ) {
	this->_fixed_point--;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed tmp(*this);
	this->_fixed_point--;
	return tmp;
}

// Min operator
Fixed &Fixed::min( Fixed &a, Fixed &b ) {
	return (a < b) ? a : b;
}

Fixed const &Fixed::min( Fixed const &a, Fixed const &b ) {
	return (a < b) ? a : b;
}

// Max operator
Fixed &Fixed::max( Fixed &a, Fixed &b ) {
	return (a > b) ? a : b;
}

Fixed const &Fixed::max( Fixed const &a, Fixed const &b ) {
	return (a > b) ? a : b;
}

// Getters / Setters
int Fixed::getRawBits(void) const 
{
	return (this->_fixed_point);
}

void Fixed::setRawBits(int const rawBits)
{
	this->_fixed_point = rawBits;
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
