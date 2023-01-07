#include "Bureaucrat.hpp"

#define RED "\x1b[0;31m"
#define BLUE "\x1b[34;1m"
#define RESET "\x1b[0m"

int main(void)
{
	{
		std::cout << BLUE << "---------- Bureaucrat constructor test ----------" << RESET << std::endl;
		try
		{
			for (int i = 149; i <= 151; i++)
			{
				Bureaucrat carrot("carrot", i); // 149, 150, 151
			}
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "\n";
		try
		{
			for (int i = 2; i >= 0; i--)
				Bureaucrat pumkin("pumkin", i); // 2, 1, 0
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << BLUE << "\n------------ Bureaucrat increase test -----------" << RESET << std::endl;
		Bureaucrat kiwi("kiwi", 3);
		try
		{
			for (int i = 0; i < 3; i++)
			{
				kiwi.increaseGrade(); // 2, 1, 0
				std::cout << kiwi << RESET << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << BLUE << "\n------------ Bureaucrat decrease test -----------" << RESET << std::endl;
		Bureaucrat toma("toma", 148);
		try
		{
			for (int i = 0; i < 3; i++)
			{
				toma.decreaseGrade(); // 149, 150, 151
				std::cout << toma << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	return (0);
}