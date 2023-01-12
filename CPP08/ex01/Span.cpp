#include "Span.hpp"

Span &Span::operator=(const Span &src)
{
	size_ = src.size_;
	v = src.v;
	return *this;
}

void Span::addNumber(int n)
{
	if (v.size() >= size_)
		throw OutOfSizeException();
	v.push_back(n);
}

long Span::shortestSpan()
{
	long result;

	if (v.size() < 2)
		throw NotEnoughSizeException();

	std::vector<int> copy(v);
	std::sort(copy.begin(), copy.end());

	std::vector<int>::iterator prev_it = copy.begin();
	std::vector<int>::iterator curr_it = prev_it + 1;

	std::cout << "sorted: ";
	for (int i = 0; (unsigned long)i < copy.size(); i++)
	{
		std::cout << copy[i] << " ";
	}
	std::cout << std::endl;
	result = static_cast<long>(*curr_it) - *prev_it;
	prev_it++;
	curr_it++;
	while (curr_it != copy.end())
	{
		int temp = static_cast<long>(*curr_it) - *prev_it;
		if (temp < result)
			result = temp;
		prev_it++;
		curr_it++;
	}
	return result;
}

long Span::longestSpan()
{
	long result;

	if (v.size() < 2)
		throw NotEnoughSizeException();

	std::vector<int> copy(v);
	std::sort(copy.begin(), copy.end());
	
	result = static_cast<long>(copy.back() - copy.front());

	return result;
}

void Span::fillSpan()
{
	srand(time(NULL));

	std::cout << "random nums: ";
	for (unsigned int i = 0; i < size_; i++)
	{
		int num = rand() % 100;
		std::cout << num << " ";
		addNumber(num);
	}
	std::cout << std::endl;
}