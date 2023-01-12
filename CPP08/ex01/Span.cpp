#include "Span.hpp"

Span &Span::operator=(const Span &src)
{
	this->_size = src._size;
	this->_v = src._v;
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_v.size() >= this->_size)
		throw OutOfSizeException();
	this->_v.push_back(n);
}

long Span::shortestSpan(void) const
{
	long result;

	if (this->_v.size() < 2)
		throw NotEnoughSizeException();

	std::vector<int> copy(this->_v);
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

long Span::longestSpan(void) const
{
	long result;

	if (this->_v.size() < 2)
		throw NotEnoughSizeException();

	result = static_cast<long>(*std::max_element(this->_v.begin(), this->_v.end())) - *std::min_element(this->_v.begin(), this->_v.end());

	return result;
}

void Span::fillSpan()
{
	srand(time(NULL));

	std::cout << "random nums: ";
	for (unsigned int i = 0; i < this->_size; i++)
	{
		int num = rand() % 100;
		std::cout << num << " ";
		addNumber(num);
	}
	std::cout << std::endl;
}