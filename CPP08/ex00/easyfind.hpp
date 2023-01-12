#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

class NotFoundException : public std::exception
{
public:
	const char *what() const throw()
	{
		return ("Number not found.");
	}
};

template<typename T>
typename T::iterator easyfind(T &container, int to_find)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), to_find);
	if (iter == container.end())
		throw NotFoundException();
	return iter;
}
#endif