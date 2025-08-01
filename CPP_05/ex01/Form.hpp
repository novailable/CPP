#ifndef	FORM_HPP
#define	FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form 
{
	private:
		const std::string	_name;
		const int	_sign_grade;
		const int	_exec_grade;
		bool	_sign;
	public:
		Form();
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form();
		
		Form(std::string name, int sign_grade);
		Form(std::string name, int sign_grade, int exec_grade);
		std::string	get_name() const;
		int	get_sign_grade() const;
		int	get_exec_grade() const;
		bool is_signed() const;

		void	beSigned(const Bureaucrat &bureau);

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

std::ostream	&operator<<(std::ostream &out, const Form &other);

#endif