#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

#define RED "\x1b[0;31m"
#define BLUE "\x1b[34;1m"
#define RESET "\x1b[0m"

int main(void)
{
	{	
		std::cout << BLUE << "---------- Form construction test ----------" << RESET << std::endl;
		try
		{
			for(int i = 149; i <= 151; i++)
				Form vacation("Kakao", i, 10);	// sign grade : 149, 150, 151
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "\n";
		try
		{
			for(int i = 2; i >= 0; i--)
				Form kakao_friends("Kakao Friends", 10, i);	// exec grade 2, 1, 0
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << BLUE << "\n------------ Form sign test -----------" << RESET << std::endl;
		Bureaucrat ryan("Ryan", 43);
		Form vacation ("Kakao", 40, 40);
		std::cout << "\n";
		for(int i = 0; i < 3; i++)
		{
			ryan.increaseGrade(); // sign grade : 42, 41, 40
			ryan.signForm(vacation);
			std::cout << vacation << "\n\n";
		}
	}
	return (0);
}
