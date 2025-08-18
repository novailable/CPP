#ifndef	SHRUBBERYCREATIONFORM_HPP
#define	SHRUBBERYCREATIONFORM_HPP

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Creates a file <target>_shrubbery in the working directory and writes ASCII trees
// inside it.
#include <fstream>
#include <sstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define B "\033[0;33m"
#define G "\033[32m"
#define O "\033[38;5;208m"
#define W "\033[0m"
#define L "\033[38;2;195;202;111m"

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		bool	action() const;
	public:
		std::string	get_target() const;
		std::string	get_filename() const;
		ShrubberyCreationForm(std::string target);		
};

#endif