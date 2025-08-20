#ifndef	SHRUBBERYCREATIONFORM_HPP
#define	SHRUBBERYCREATIONFORM_HPP

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Creates a file <target>_shrubbery in the working directory and writes ASCII trees
// inside it.
#include <fstream>
#include <sstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		bool	action() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);		
		std::string	get_filename() const;
};

#endif