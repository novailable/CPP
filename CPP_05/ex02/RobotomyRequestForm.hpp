#ifndef	ROBOTOMYREQUESTFORM_HPP
#define	ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(std::string target);
		bool	action() const;
};

#endif