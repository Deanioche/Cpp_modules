#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	Bureaucrat(const Bureaucrat &origin);
	Bureaucrat &operator=(const Bureaucrat &origin);

public:
	Bureaucrat(void);
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat(void);

	std::string getName(void) const;
	int getGrade(void) const;

	void increaseGrade(void);
	void decreaseGrade(void);

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
