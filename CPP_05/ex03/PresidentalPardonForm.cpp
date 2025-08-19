#include "PresidentalPardonForm.hpp"

PresidentalPardonForm::PresidentalPardonForm(std::string target) :
	AForm(target + "'s Presidental Pardon Form", 25, 5), _target(target) {}

bool	PresidentalPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return (true);
}
