#ifndef	FORM_HPP
#define	FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm 
{
	private:
		const std::string	_name;
		const int _req_grade;
		bool	_sign;
	public:
		AForm();
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		~AForm();
		
		AForm(std::string name, int req_grade);
		std::string	get_name() const;
		int	get_req_grade() const;
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

std::ostream	&operator<<(std::ostream &out, const AForm &other);

#endif