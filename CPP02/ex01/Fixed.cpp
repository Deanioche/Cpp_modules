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

// roundf는 파라미터롤 들어오는 float 값을 가장 가까운 int로 변환
/**
 * _fractionalBits : 8
	1 << _fractionalBits : 256
	f * (1 << _fractionalBits) : 10859.5
	roundf(f * (1 << _fractionalBits)) : 10860
 **/
Fixed::Fixed( float const f ) : _fixed_point( roundf(f * (1 << _fractionalBits)) )
{
	// test
	std::cout <<  "f : " << (f) << "\n";
	std::cout << "_fractionalBits : " << (_fractionalBits) << "\n";
	std::cout << "1 << _fractionalBits : " << (1 << _fractionalBits) << "\n";
	std::cout << "f * (1 << _fractionalBits) : " << (f * (1 << _fractionalBits)) << "\n";
	std::cout << "roundf(f * (1 << _fractionalBits)) : " << roundf(f * (1 << _fractionalBits)) << "\n";
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

void Fixed::setRawBits(int const rawBits)
{
	std::cout << "\033[0;setRawBits member funtion called.\033[0m" << std::endl;
	this->_fixed_point = rawBits;
	return ;
}


// Public Functions
int Fixed::toInt(void) const
{
	// Fixed::_factioncalBits는 static이므로 인스턴스에서 호출하는게 아닌, 클래스에서 바로 호출.
	return (this->_fixed_point >> Fixed::_fractionalBits);	
}

/**
 * static_cast<type>
   compile 타임에 형변환에 대한 타입 오류를 잡아줍니다.

	실수와 정수, 열거형과 정수형, 실수와 실수 사이의 변환 등을 허용한다.
	arr -> pointer로 변경 가능합니다.

	function -> function pointer로 변경 가능합니다.
*/
float Fixed::toFloat(void) const
{
	std::cout << "static_cast<float>(_fixed_point) : " << (static_cast<float>(_fixed_point)) << "\n";
	std::cout << "static_cast<float>(_fixed_point) / (1 << 8) : " << (static_cast<float>(_fixed_point) / (1 << Fixed::_fractionalBits)) << "\n";

	return (static_cast<float>(_fixed_point) / (1 << Fixed::_fractionalBits));
}


// Operator <<
std::ostream& operator<<( std::ostream& os, const Fixed& number )
{
	return (os << number.toFloat());
}
