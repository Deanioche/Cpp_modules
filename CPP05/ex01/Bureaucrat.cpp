#include "Bureaucrat.hpp"

#define RED "\x1b[0;31m"
#define BLUE "\x1b[0;34m"
#define GREEN "\x1b[0;32m"
#define MAGENTA "\x1b[0;35m"
#define RESET "\x1b[0m"

Bureaucrat::Bureaucrat(void) : _name("Default")
{
	std::cout << "[ Bureaucrat Default Constructor called ]" << std::endl;
	this->_grade = 150;
	std::cout << "Default Bureaucrat is created " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "[ Bureaucrat Constructor called ]" << std::endl;
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade = grade;
	std::cout << "Bureaucrat is created " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &origin) : _name(origin.getName())
{
	std::cout << "[ Bureaucrat Copy Constructor called ]" << std::endl;
	this->_grade = origin.getGrade();
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " is destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &origin)
{
	std::cout << "[ Form Copy Assign operator called ]" << std::endl;
	if (this != &origin)
		this->_grade = origin.getGrade();
	std::cout << "Form is copied (only grade) " << *this << std::endl;
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::ostream &operator<<(std::ostream &c, const Bureaucrat &b)
{
	c << "[ Bureaucrat name : " << b.getName() << ", grade : " << b.getGrade() << " ]";
	return (c);
}

void Bureaucrat::increaseGrade(void)
{
	if (this->_grade - 1 < 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
	std::cout << MAGENTA << "Bureaucrat " << this->_name << "'s grade is increased (current : " << this->_grade << ")" << RESET << std::endl;
}

void Bureaucrat::decreaseGrade(void)
{
	if (this->_grade + 1 > 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
	std::cout << BLUE << "Bureaucrat " << this->_name << "'s grade is decreased (current : " << this->_grade << ")" << RESET << std::endl;
}

void Bureaucrat::signForm(Form &f) const
{
	std::cout << GREEN << "Bureaucrat " << this->_name << " trying to sign the Form " << f.getName() << "...." << RESET << std::endl;
	try
	{
		f.beSigned(*this);
		std::cout << GREEN << "Bureaucrat " << this->_name << " signed the Form " << f.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Bureaucrat " << this->_name << " couldn’t sign the Form " << f.getName() << " because " << e.what() << RESET << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Error : Grade Is Too High");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Error : Grade Is Too Low");
}
