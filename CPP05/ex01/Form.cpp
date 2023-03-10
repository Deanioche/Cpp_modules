#include "Form.hpp"

#define RED "\x1b[0;31m"
#define GREEN "\x1b[0;32m"
#define RESET "\x1b[0m"

Form::Form(void) : _name("Default"), _required_sign_grade(150), _required_exec_grade(150)
{
	std::cout << "[ Form Default Constructor called ]" << std::endl;
	this->_signed = false;
	std::cout << "Default Form is created " << *this << std::endl;
}

Form::Form(const std::string name, const int required_sign_grade, const int required_exec_grade) : _name(name), _required_sign_grade(required_sign_grade), _required_exec_grade(required_exec_grade)
{
	std::cout << "[ Form Constructor called ]" << std::endl;
	if (required_sign_grade < 1 || required_exec_grade < 1)
	{
		std::cout << RED << "Error : " << RESET;
		throw (Form::GradeTooHighException());
	}
	else if (required_sign_grade > 150 || required_exec_grade > 150)
	{
		std::cout << RED << "Error : " << RESET;
		throw (Form::GradeTooLowException());
	}
	this->_signed = false;
	std::cout << "Form is created " << *this << std::endl;
}

Form::Form(const Form &origin) : _name(origin.getName()), _required_sign_grade(origin.getRequiredSignGrade()), _required_exec_grade(origin.getRequiredExecGrade())
{
	std::cout << "[ Form Copy Constructor called ]" << std::endl;
	this->_signed = origin.isSigned();
	std::cout << "Form is copied " << *this << std::endl;

}

Form::~Form(void)
{
	std::cout << "Form " << this->_name << " is destroyed" << std::endl;
}

Form &Form::operator= (const Form &origin)
{
	std::cout << "[ Form Copy Assign operator called ]" << std::endl;
	if (this != &origin)
		this->_signed = isSigned();
	std::cout << "Form is copied (only sign) " << *this << std::endl;
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::isSigned(void) const
{
	return (this->_signed);
}

int Form::getRequiredSignGrade(void) const
{
	return (this->_required_sign_grade);
}

int Form::getRequiredExecGrade(void) const
{
	return (this->_required_exec_grade);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_required_sign_grade)
	{
		this->_signed = true;
		std::cout << GREEN << "Success : " << RESET;
	}
	else
	{
		std::cout << RED << "Fail : " << RESET;
		throw(Form::GradeTooLowException());
	}
}

std::ostream & operator<<(std::ostream &c, const Form &f)
{
	c << "[ Form name : " << f.getName() << ", is sigined : ";
	if (f.isSigned() == true)
		c << "true";
	else
		c << "false";
	c << ", required grade : sign(" << f.getRequiredSignGrade() << ") / exec(" << f.getRequiredExecGrade() << ") ]";
	return (c);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade Is Too High");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade Is Too Low");
}
