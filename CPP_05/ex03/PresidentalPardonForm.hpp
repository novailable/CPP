#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentalPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentalPardonForm(std::string target);
		bool	action() const;
};

#endif