#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
private:
	unsigned int size_;
	std::vector<int> v;

	Span();

public:
	Span(unsigned int N) : size_(N) {};
	Span(const Span &src) : size_(src.size_), v(src.v) {};
	Span &operator=(const Span &src);
	~Span(){};

	void addNumber(int n);
	long shortestSpan();
	long longestSpan();
	void fillSpan();

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