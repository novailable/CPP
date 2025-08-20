#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentalPardonForm : public AForm
{
	private:
		bool	action() const;
	public:
		PresidentalPardonForm();
		PresidentalPardonForm(const PresidentalPardonForm &other);
		PresidentalPardonForm	&operator=(const PresidentalPardonForm &other);
		~PresidentalPardonForm();

		PresidentalPardonForm(std::string target);		
};

#endif