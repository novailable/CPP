#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern();

		AForm*	makeForm(std::string form_name, std::string target);

		class	FormNameException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

#endif