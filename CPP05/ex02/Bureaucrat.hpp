#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &origin);
	~Bureaucrat(void);
	Bureaucrat &operator=(const Bureaucrat &origin);

	std::string getName(void) const;
	int getGrade(void) const;

	void increaseGrade(void);
	void decreaseGrade(void);
	void signForm(AForm &f) const;
	void executeForm(AForm const &form) const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &c, const Bureaucrat &b);

#endif
