#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _required_sign_grade;
	const int _required_exec_grade;

public:
	AForm(void);
	AForm(const std::string name, const int required_sign_grade, const int required_exec_grade);
	AForm(const AForm &origin);
	virtual ~AForm(void);
	AForm &operator=(const AForm &origin);

	std::string getName(void) const;
	bool isSigned(void) const;
	void setSigned(bool parm);
	int getRequiredSignGrade(void) const;
	int getRequiredExecGrade(void) const;

	void beSigned(const Bureaucrat &b);
	virtual void execute(Bureaucrat const &executor) const = 0;

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
	class NotSignedFormException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class ExecFailException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &c, const AForm &f);

#endif
