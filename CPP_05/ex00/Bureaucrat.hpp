#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class	Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;
		void	validateGrade(int grade);
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

		Bureaucrat	&operator++();
		Bureaucrat	operator++(int);
		Bureaucrat	&operator--();
		Bureaucrat	operator--(int);

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