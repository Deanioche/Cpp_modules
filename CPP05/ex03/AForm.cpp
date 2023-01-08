#include "AForm.hpp"

#define RED "\x1b[0;31m"
#define GREEN "\x1b[0;32m"
#define RESET "\x1b[0m"

AForm::AForm(void) : _name("Default"), _required_sign_grade(150), _required_exec_grade(150)
{
	std::cout << "[ Form Default Constructor called ]" << std::endl;
	this->_signed = false;
	std::cout << "Default Form is created " << *this << std::endl;
}

AForm::AForm(const std::string name, const int required_sign_grade, const int required_exec_grade) : _name(name), _required_sign_grade(required_sign_grade), _required_exec_grade(required_exec_grade)
{
	std::cout << "[ Form Constructor called ]" << std::endl;
	if (required_sign_grade < 1 || required_exec_grade < 1)
	{
		std::cout << RED << "Error : " << RESET;
		throw(AForm::GradeTooHighException());
	}
	else if (required_sign_grade > 150 || required_exec_grade > 150)
	{
		std::cout << RED << "Error : " << RESET;
		throw(AForm::GradeTooLowException());
	}
	this->_signed = false;
	std::cout << "Form is created " << *this << std::endl;
}

AForm::AForm(const AForm &origin) : _name(origin.getName()), _required_sign_grade(origin.getRequiredSignGrade()), _required_exec_grade(origin.getRequiredExecGrade())
{
	std::cout << "[ Form Copy Constructor called ]" << std::endl;
	this->_signed = origin.isSigned();
	std::cout << "Form is copied " << *this << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "Form " << _name << " is destroyed" << std::endl;
}

AForm &AForm::operator=(const AForm &origin)
{
	std::cout << "[ Form Copy Assign operator called ]" << std::endl;
	if (this != &origin)
		this->_signed = isSigned();
	std::cout << "Form is copied (only sign) " << *this << std::endl;
	return (*this);
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::isSigned(void) const
{
	return (this->_signed);
}

void AForm::setSigned(bool parm)
{
	this->_signed = parm;
}

int AForm::getRequiredSignGrade(void) const
{
	return (this->_required_sign_grade);
}

int AForm::getRequiredExecGrade(void) const
{
	return (this->_required_exec_grade);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_required_sign_grade)
	{
		this->_signed = true;
		std::cout << GREEN << "Success : " << RESET;
	}
	else
	{
		std::cout << RED << "Fail : " << RESET;
		throw(AForm::GradeTooLowException());
	}
}

std::ostream &operator<<(std::ostream &c, const AForm &f)
{
	c << "[ Form name : " << f.getName() << ", is sigined : ";
	if (f.isSigned() == true)
		c << "true";
	else
		c << "false";
	c << ", required grade : sign(" << f.getRequiredSignGrade() << ") / exec(" << f.getRequiredExecGrade() << ") ]";
	return (c);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade Is Too High");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade Is Too Low");
}

const char *AForm::NotSignedFormException::what(void) const throw()
{
	return ("Form is not signed");
}

const char *AForm::ExecFailException::what(void) const throw()
{
	return ("Fail To Execute");
}