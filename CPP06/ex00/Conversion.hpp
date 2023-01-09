#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <string>
#include <cmath>

class Conversion
{
private:
	std::string _value;
	Conversion(void);

public:
	Conversion(std::string const &input) : _value(input) {};
	Conversion(Conversion const &src) : _value(src._value) {};
	Conversion &operator=(Conversion const &src);
	~Conversion(void) {};

	char toChar(void) const;
	int toInt(void) const;
	float toFloat(void) const;
	double toDouble(void) const;

	class ImpossibleException : public std::exception
	{
		const char *what(void) const throw()
		{
			return "impossible";
		}
	};
	class NonDisplayableException : public std::exception
	{
		const char *what(void) const throw()
		{
			return "Non displayable";
		}
	};
};

std::ostream& operator<<(std::ostream &out, const Conversion &ref);

#endif