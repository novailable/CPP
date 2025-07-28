#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#include "Form.hpp"

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
		static void validateGrade(int grade);
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