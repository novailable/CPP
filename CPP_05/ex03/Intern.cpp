#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other;}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

template <typename T>
AForm*	createForm(const std::string& target) {return (new T(target));}

AForm*	Intern::makeForm(std::string form_name, std::string target)
{
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm* (*creators[3])(const std::string&) = {
        &createForm<ShrubberyCreationForm>,
        &createForm<RobotomyRequestForm>,
        &createForm<PresidentalPardonForm>
    };

	for (int i = 0; i < 3; ++i)
	{
		if (form_name == names[i])
		{
			AForm	*result = creators[i](target);
			std::cout << "Intern creates " << result->get_name() << std::endl;
			return result;
		}
	}
	throw FormNameException();
}

const char*	Intern::FormNameException::what() const throw()
{
	return ("wrong form name!");
}
