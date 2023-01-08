#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy request", R_SIGN_GRADE, R_EXEC_GRADE)
{
	std::cout << "[ RobotomyRequestForm Default Constructor called ]" << std::endl;
	this->_target = "";
	std::cout << "RobotomyRequestForm Form is created " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", R_SIGN_GRADE, R_EXEC_GRADE)
{
	std::cout << "[ RobotomyRequestForm Constructor called ]" << std::endl;
	this->_target = target;
	std::cout << "RobotomyRequestForm Form is created " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &origin) : AForm("robotomy request", origin.getRequiredSignGrade(), origin.getRequiredExecGrade())
{
	std::cout << "[ RobotomyRequestForm Copy Constructor called ]" << std::endl;
	this->_target = origin.getTarget();
	setSigned(origin.isSigned());
	std::cout << "RobotomyRequestForm is copied " << *this << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is destroyed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &origin)
{
	std::cout << "[ RobotomyRequestForm Copy Assign operator called ]" << std::endl;
	if (this != &origin)
	{
		this->_target = origin.getTarget();
		setSigned(origin.isSigned());
	}
	std::cout << "RobotomyRequestForm is copied (only Target and sign) " << *this << std::endl;
	return (*this);
}

const std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static int first_execute;

	if (first_execute == 0)
	{
		first_execute = 1;
		srand(time(NULL));
	}
	if (isSigned() == false)
		throw(AForm::NotSignedFormException());
	else if (executor.getGrade() > getRequiredExecGrade())
		throw(AForm::GradeTooLowException());
	else
	{
		std::cout << "drrrr... drrrrrrr..." << std::endl;
		if (rand() % 2 == 0)
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Fail to robotomize " << this->_target << std::endl;
	}
}

std::ostream &operator<<(std::ostream &c, const RobotomyRequestForm &f)
{
	c << "[ Form name : " << f.getName() << ", is sigined : ";
	if (f.isSigned() == true)
		c << "true";
	else
		c << "false";
	c << ", required grade : sign(" << f.getRequiredSignGrade() << ") / exec(" << f.getRequiredExecGrade() << ") , target : "<< f.getTarget() << " ]";
	return (c);
}
