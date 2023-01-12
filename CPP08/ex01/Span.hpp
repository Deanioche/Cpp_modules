#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
private:
	unsigned int _size;
	std::vector<int> _v;

	Span(void);

public:
	Span(unsigned int N) : _size(N) {};
	Span(const Span &src) : _size(src._size), _v(src._v) {};
	Span &operator=(const Span &src);
	~Span(void){};

	void addNumber(int n);
	long shortestSpan(void) const;
	long longestSpan(void) const;
	void fillSpan(void);

	class OutOfSizeException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Out of size exception.");
		}
	};

	class NotEnoughSizeException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Not enough size exception.");
		}
	};
};

#endif