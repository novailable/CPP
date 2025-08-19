#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm(target + "'s robot form", 72, 45), _target(target)
{
	std::srand(std::time(0));
}

bool	RobotomyRequestForm::action() const
{
	std::cout << "Drilling... \nWhizzzz!!!! Whizzzzzzzz........\n";
	 if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << _target << std::endl;
	return (true);
}
