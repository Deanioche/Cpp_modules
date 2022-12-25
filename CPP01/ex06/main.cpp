#include "Harl.h"
#include "iostream"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "error : Argument is required" << std::endl;
		return (1);
	}
	Harl harl;
	harl.harlFilter(av[1]);
}
