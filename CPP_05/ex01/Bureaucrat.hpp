#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define CYAN		"\033[36m"
#define BOLD		"\033[1m"

template <typename T>
void	validateGrade(int grade)
{
	if (grade < 1)
		throw typename T::GradeTooHighException();
	if (grade > 150)
		throw typename T::GradeTooLowException();
}
class	Form;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat(std::string name, int grade);
		std::string	getName(void) const;
		int	getGrade(void) const;
		void	setGrade(int grade);

		void	increaseGrade(unsigned int num);
		void	decreaseGrade(unsigned int num);

		void	increment();
		void	decrement();

		Bureaucrat	&operator++();
		Bureaucrat	operator++(int);
		Bureaucrat	&operator--();
		Bureaucrat	operator--(int);

		void	signForm(Form &form);

		class GradeTooLowException : public std::exception 
		{
			public:
				const char* what() const throw();
		};

		class GradeTooHighException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bure);

#endif