#ifndef	AFORM_HPP
#define	AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm 
{
	private:
		const std::string	_name;
		const int	_sign_grade;
		const int	_exec_grade;
		bool	_sign;
	protected:
		virtual bool	action() const = 0;
	public:
		AForm();
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		virtual ~AForm();
		
		// AForm(std::string name, int sign_grade);
		AForm(int sign_grade, int exec_grade);
		AForm(std::string name, int sign_grade, int exec_grade);
		std::string	get_name() const;
		int	get_sign_grade() const;
		int	get_exec_grade() const;
		bool is_signed() const;

		void	beSigned(const Bureaucrat &bureau);
		void	execute(Bureaucrat const & executor) const;
		

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

		class	SignException : public std::exception
		{
			private:
				std::string	_msg;
			public:
				SignException(const std::string& msg);
				const char*	what() const throw();
				~SignException() throw() {}
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &other);


#endif