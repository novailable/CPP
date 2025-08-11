#include "AForm.hpp"

AForm::AForm() : _name("anonymous"), _req_grade(0), _sign(false) {}

AForm::AForm(const AForm &other) : _name(other._name), _req_grade(other._req_grade), _sign(other._sign) {}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		_sign = other._sign;
	return (*this);
}

AForm::~AForm() {}

AForm::AForm(std::string name, int req_grade) : _name(name), _req_grade(req_grade), _sign(false)
{
	Bureaucrat::validateGrade(_req_grade);
}

std::string	AForm::get_name() const {return (_name);}

int	AForm::get_req_grade() const {return (_req_grade);}

bool	AForm::is_signed() const {return (_sign);}

void	AForm::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() > _req_grade)
		throw	GradeTooLowException();
	_sign = true;
	std::cout << bureau.getName() << " signed " << _name << std::endl;
}


const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream	&operator<<(std::ostream &out, const AForm &other)
{
	out << "Form : '" << other.get_name() << "' require grade: '" << other.get_req_grade()
		<< (other.is_signed() ? "' is signed already." : "' haven't signed yet!");
	return (out);
}