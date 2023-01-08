#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define P_SIGN_GRADE 25
#define P_EXEC_GRADE 5

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &origin);

public:
	PresidentialPardonForm(const std::string target);
	~PresidentialPardonForm(void);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &origin);

	const std::string getTarget(void) const;

	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &c, const PresidentialPardonForm &f);

#endif
