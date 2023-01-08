#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _required_sign_grade;
	const int _required_exec_grade;

public:
	Form(void);
	Form(const std::string name, const int required_sign_grade, const int required_exec_grade);
	Form(const Form &origin);
	~Form(void);
	Form &operator=(const Form &origin);

	std::string getName(void) const;
	bool isSigned(void) const;
	int getRequiredSignGrade(void) const;
	int getRequiredExecGrade(void) const;

	void beSigned(const Bureaucrat &b);

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

std::ostream &operator<<(std::ostream &c, const Form &f);

#endif
