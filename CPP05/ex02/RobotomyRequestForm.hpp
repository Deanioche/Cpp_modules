#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>

# define R_SIGN_GRADE 72
# define R_EXEC_GRADE 45

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &origin);
	public:
		// constructor, canonical form
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm & operator=(const RobotomyRequestForm &origin);
		// accessor
		const std::string getTarget(void) const;
		// others
		void execute(Bureaucrat const & executor) const;
};

std::ostream &	operator<<(std::ostream &c, const RobotomyRequestForm &f);

#endif
