#include "Bureaucrat.hpp"

#define RED "\x1b[0;31m"
#define BBLUE "\x1b[34;1m" 
#define RESET "\x1b[0m"

int main(void)
{
	{	
		std::cout << BBLUE << "---------- Bureaucrat constructor test ----------" << RESET << std::endl;
		try
		{
			for(int i = 149; i <= 151; i++)
				Bureaucrat tube("Tube", i); // 149, 150, 151
		} 
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "\n";
		try
		{
			for(int i = 2; i >= 0; i--)
				Bureaucrat muzi("Muzi", i);	// 2, 1, 0
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << BBLUE << "\n------------ Bureaucrat increase test -----------" << RESET << std::endl;
		Bureaucrat ryan("Ryan", 3);
		try
		{
			for(int i = 0; i < 3; i++)
			{
				ryan.increaseGrade();	//	2, 1, 0
				std::cout << ryan << RESET << std::endl;
			}
		} catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << BBLUE << "\n------------ Bureaucrat decrease test -----------" << RESET << std::endl;
		Bureaucrat apeach("Apeach", 148);
		try
		{
			for(int i = 0; i < 3; i++)
			{
				apeach.decreaseGrade();	// 149, 150, 151
				std::cout << apeach << std::endl;
			}
		} catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	return (0);
}
