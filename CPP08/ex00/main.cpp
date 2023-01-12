#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		std::cout << *iter << " "; 
	}
	std::cout << std::endl;

	try
	{
		std::vector<int>::iterator it1 = easyfind(v, 4);
		std::cout << *it1 << std::endl;

		std::vector<int>::iterator it2 = easyfind(v, 7);
		std::cout << *it2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}