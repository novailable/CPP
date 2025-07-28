#include "Form.hpp"

Form::Form() : _name("anonymous"), _req_grade(0) {}

Form::Form(const Form &other) : _name(other._name), _req_grade(other._req_grade), _sign(other._sign) {}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		_sign = other._sign;
	return (*this);
}

Form::~Form() {}

Form::Form(std::string name, int req_grade) : _name(name), _req_grade(req_grade) 
{
	Bureaucrat::validateGrade(_req_grade);
}

std::string	Form::get_name() const {return (_name);}

int	Form::get_req_grade() const {return (_req_grade);}

bool	Form::get_signed() const {return (_sign);}

void	Form::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() < _req_grade)
		throw	GradeTooLowException();
	_sign = true;
}

std::ostream	&operator<<(std::ostream &out, const Form &other) const
{
	out << "Form " << other.get_name() << " require " << other.get_req_grade()
		<< other.get_signed() ? "is signed already." : "haven't signed yet!";
	return (out);
}