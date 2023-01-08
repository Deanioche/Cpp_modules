#include "Intern.hpp"

int main(void)
{
	Intern green;
	AForm *form;
	std::cout << std::endl;

	form = green.makeForm("shrubbery creation", "Harl");
	delete form;
	std::cout << std::endl;
	form = green.makeForm("robotomy request", "Harl");
	delete form;
	std::cout << std::endl;
	form = green.makeForm("presidential pardon", "Harl");
	delete form;
	std::cout << std::endl;
	form = green.makeForm("blah blah", "Harl");
	delete form;

	return (0);
}
