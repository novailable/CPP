#ifndef	FORM_HPP
#define	FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureacrat;

class	Form
{
	private:
		const std::string	_name;
		const int _req_grade;
		bool	_sign = false;
	public:
		Form();
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form();
		
		Form(std::string name, int req_grade);
		std::string	get_name() const;
		int	get_req_grade() const;
		bool get_signed() const;

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

std::ostream	&operator<<(std::ostream &out, const Form &other) const;

#endif