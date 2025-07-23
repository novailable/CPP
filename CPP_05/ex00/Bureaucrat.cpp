#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("anonymous"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

void	Bureaucrat::validateGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) 
{
	validateGrade(_grade);
}

std::string	Bureaucrat::getName(void) const {return(_name);}

int	Bureaucrat::getGrade(void) const {return(_grade);}

void	Bureaucrat::setGrade(int grade)
{
	validateGrade(grade);
	_grade = grade;
}

void	Bureaucrat::increaseGrade(unsigned int num)
{
	validateGrade(_grade - num);
	_grade -= num;
}

void	Bureaucrat::decreaseGrade(unsigned int num)
{
	validateGrade(_grade + num);
	_grade += num;
}

Bureaucrat	&Bureaucrat::operator++()
{
	validateGrade(_grade - 1);
	_grade--;
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	validateGrade(_grade - 1);
	Bureaucrat tmp(*this);
	--_grade;
	return tmp;
}

Bureaucrat	&Bureaucrat::operator--()
{
	validateGrade(_grade + 1);
	_grade++;
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int)
{
	validateGrade(_grade + 1);
	Bureaucrat tmp(*this);
	++_grade;
	return tmp;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bure)
{
	out << bure.getName() << ", bureaucrat grade " << bure.getGrade();
	return (out);
}
