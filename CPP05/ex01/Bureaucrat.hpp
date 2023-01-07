#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		// constructor, canonical form
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &origin);
		~Bureaucrat(void);
		Bureaucrat &operator= (const Bureaucrat &origin);
		// accessor
		std::string getName(void) const;
		int getGrade(void) const;
		// others
		void increaseGrade(void);
		void decreaseGrade(void);
		void signForm(Form & f) const;
		// exception
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

std::ostream &	operator<<(std::ostream &c, const Bureaucrat &b);

#endif
