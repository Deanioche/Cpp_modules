#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#define S_SIGN_GRADE 145
#define S_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &origin);

public:
	ShrubberyCreationForm(const std::string target);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &origin);

	const std::string getTarget(void) const;

	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &c, const ShrubberyCreationForm &f);

#endif
