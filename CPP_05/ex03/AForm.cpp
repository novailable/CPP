#include "AForm.hpp"

AForm::AForm() : _name("anonymous"), _sign_grade(150), _exec_grade(150), _sign(false), _target("unknown") {}

AForm::AForm(const AForm &other) : _name(other._name), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade), _sign(other._sign), _target(other._target) {}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_target = other._target;
		_sign = other._sign;
	}
	return (*this);
}

AForm::~AForm() {}

AForm::AForm(int sign_grade, int exec_grade) :  _name("anonymous"), _sign_grade(sign_grade), _exec_grade(exec_grade), _sign(false), _target("unknown")
{
	validateGrade(_sign_grade);
	validateGrade(_exec_grade);
}

AForm::AForm(std::string name, int sign_grade, int exec_grade, const std::string target) :
	_name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _sign(false), _target(target)
{
	validateGrade(_sign_grade);
	validateGrade(_exec_grade);
}

std::string	AForm::get_name() const {return (_name);}

int	AForm::get_sign_grade() const {return (_sign_grade);}

int	AForm::get_exec_grade() const {return (_exec_grade);}

std::string	AForm::get_target() const {return (_target);}

bool	AForm::is_signed() const {return (_sign);}

void	AForm::beSigned(const Bureaucrat &bureau)
{
	if (this->_sign)
		throw	SignException("it's alrady signed");
	if (bureau.getGrade() > _sign_grade)
		throw	GradeTooLowException();
	_sign = true;
	std::cout << bureau.getName() << " signed " << _name << std::endl;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!_sign)
		throw SignException("it hasn't signed yet!");
	if (executor.getGrade() > _exec_grade)
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << _name << std::endl;
	action();
}

void	AForm::validateGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

AForm::SignException::SignException(const std::string &msg) : _msg(msg) {}

const char*	AForm::SignException::what() const throw()
{
	return (_msg.c_str());
}

std::ostream	&operator<<(std::ostream &out, const AForm &other)
{
	out << "Form : '" << other.get_name() << "' require grade to sign '" << other.get_sign_grade() 
		<< "' & to execute '" << other.get_exec_grade()
		<< (other.is_signed() ? "' is signed already." : "' haven't signed yet!")
		<< " & is target to '" << other.get_target();
	return (out);
}