#include "Conversion.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Error : ./ex00 (something)" << std::endl;
		return 0;
	}

	Conversion cv(av[1]);
	std::cout << cv << std::endl;
	return 0;
}