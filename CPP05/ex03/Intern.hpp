#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		// constructor, canonical form
		Intern(void);
		Intern(const Intern &origin);
		~Intern(void);
		Intern &operator= (const Intern &origin);
		// others
		AForm *makeForm(std::string name, std::string target) const;
};

#endif
