#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"

# define S_SIGN_GRADE 145
# define S_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &origin);
	public:
		// constructor, canonical form
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &origin);
		// accessor
		const std::string getTarget(void) const;
		// others
		void execute(Bureaucrat const & executor) const;
};

std::ostream &	operator<<(std::ostream &c, const ShrubberyCreationForm &f);

#endif
