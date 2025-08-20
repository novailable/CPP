#include "PresidentalPardonForm.hpp"

PresidentalPardonForm::PresidentalPardonForm() : AForm(25, 5) {}

PresidentalPardonForm::PresidentalPardonForm(const PresidentalPardonForm &other) : AForm(other) {}

PresidentalPardonForm	&PresidentalPardonForm::operator=(const PresidentalPardonForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

PresidentalPardonForm::~PresidentalPardonForm() {}

PresidentalPardonForm::PresidentalPardonForm(std::string target) :
	AForm(target + "'s Presidental Pardon Form", 25, 5, target) {}

bool	PresidentalPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return (true);
}
