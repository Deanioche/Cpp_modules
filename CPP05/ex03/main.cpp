#include "Intern.hpp"

int main(void)
{
	Intern green;
	AForm *form;
	std::cout << std::endl;

	form = green.makeForm("shrubbery creation", "CPP Module");
	delete form;
	std::cout << std::endl;
	form = green.makeForm("robotomy request", "CPP Module");
	delete form;
	std::cout << std::endl;
	form = green.makeForm("presidential pardon", "CPP Module");
	delete form;
	std::cout << std::endl;
	form = green.makeForm("blah blah", "CPP Module");
	delete form;

	return (0);
}
