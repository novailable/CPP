#include "Form.hpp"

Form::Form() : _name("anonymous"), _sign_grade(150), _exec_grade(150), _sign(false) {}

Form::Form(const Form &other) : _name(other._name), _sign_grade(other._sign_grade), _exec_grade(other._sign), _sign(other._sign) {}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		_sign = other._sign;
	return (*this);
}

Form::~Form() {}

Form::Form(std::string name, int sign_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(150), _sign(false)
{
	validateGrade<Form>(_sign_grade);
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _sign(false)
{
	validateGrade<Form>(_sign_grade);
	validateGrade<Form>(_exec_grade);
}

std::string	Form::get_name() const {return (_name);}

int	Form::get_sign_grade() const {return (_sign_grade);}

int	Form::get_exec_grade() const {return (_exec_grade);}

bool	Form::is_signed() const {return (_sign);}

void	Form::beSigned(const Bureaucrat &bureau)
{
	if (this->_sign)
		throw	SignedException();
	if (bureau.getGrade() > _sign_grade)
		throw	GradeTooLowException();
	_sign = true;
	std::cout << bureau.getName() << " signed " << _name << std::endl;
}


const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char*	Form::SignedException::what() const throw()
{
	return ("it's signed already!");
}

std::ostream	&operator<<(std::ostream &out, const Form &other)
{
	out << "Form : '" << other.get_name() << "' require grade to sign '" << other.get_sign_grade() 
		<< "' & to execute '" << other.get_exec_grade()
		<< (other.is_signed() ? "' is signed already." : "' haven't signed yet!");
	return (out);
}