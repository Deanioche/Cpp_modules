#include "Harl.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "error : Argument" << std::endl;
		return (1);
	}
	Harl harl;
	harl.harlFilter(av[1]);
	return (0);
}
