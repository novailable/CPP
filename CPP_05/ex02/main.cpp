#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"

#include <sstream>
#include <fstream>
#include <string>

std::string	tree_filename;

void	printError(std::string &msg, std::exception &e)
{
	std::cerr << RED << msg << e.what() << RESET << std::endl;
}

void	printHeader(const std::string &title)
{
	std::cout << BOLD << CYAN << "\n=== " << title << " ===\n" << RESET;
}

std::string	readFile(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	if (!file)
	{
		std::perror (RED"Error opening file");
		return ("");
	}
	else
	{
		std::perror(RED"Error opening file");
	}

	std::stringstream	buffer;
	buffer << file.rdbuf();
	return (buffer.str());
}

std::string	to_upper(std::string str)
{
	for (size_t i = 0; i < str.length(); ++i)
		str[i] = std::toupper(str[i]);
	return (str);
}

std::string	get_safe_input(std::string prompt)
{
	std::string	value;

	std::cout << YELLOW << prompt;
	if (!getline(std::cin, value) || value.empty())
	{
		std::cin.clear();
		std::cout << "\neof detected quitting." << std::endl;
		exit(0);
	}
	return (value);
}

void	testOCF()
{
	printHeader("Shrubbery Form OCF");
	ShrubberyCreationForm	org;
	ShrubberyCreationForm	shrubby("Aug20");
	std::cout << GREEN << "org : " << org << std::endl;
	std::cout << "shrubby : " << shrubby << std::endl;
	std::cout << "copy(shrubby) : " << ShrubberyCreationForm(shrubby) << std::endl;
	org = shrubby;
	std::cout << "org = shrubby, org : " << org << std::endl;
	
	printHeader("Robotomy Form OCF");
	RobotomyRequestForm	r_org;
	RobotomyRequestForm	roboto("1715");
	std::cout << "r_org : " << r_org << std::endl;
	std::cout << "roboto : " << roboto << std::endl;
	std::cout << "r_copy(roboto) : " << RobotomyRequestForm(roboto) << std::endl;
	r_org = roboto;
	std::cout << "r_org = roboto, r_org : " << r_org << std::endl;

	printHeader("Presidental Pardon Form OCF");
	PresidentalPardonForm	p_org;
	PresidentalPardonForm	pardon("Forger");
	std::cout << "p_org : " << p_org << std::endl;
	std::cout << "pardon : " << pardon << std::endl;
	std::cout << "p_copy(pardon) : " << PresidentalPardonForm(pardon) << std::endl;
	p_org = pardon;
	std::cout << "p_org = pardon, p_org : " << p_org << std::endl;
}


void	testShrubberyCreationForm(Bureaucrat &Theona)
{
	Bureaucrat	Anoeth("Anoeth", 140);

	printHeader("Shrubbery Form Invalid Test");
	ShrubberyCreationForm	shrubbery("Laura");
	Anoeth.executeForm(shrubbery);
	std::cout << GREEN;
	Anoeth.signForm(shrubbery);
	Anoeth.executeForm(shrubbery);

	printHeader("Shrubbery Form Valid Test");
	std::cout << GREEN;
	ShrubberyCreationForm	shberry("Victor");
	Theona.signForm(shberry);
	Theona.executeForm(shberry);
	std::cout << YELLOW;
	tree_filename = shberry.get_filename();
	
	std::cout << tree_filename << " created" << RESET << std::endl;
}

void	testRobotmyRequestForm(Bureaucrat &Theona)
{
	Bureaucrat Anoeht("Anoeht", 60);

	printHeader("RobotmyRequestForm Invalid Test");
	RobotomyRequestForm	roboform("Khan");
	Anoeht.executeForm(roboform);
	std::cout << GREEN;
	Anoeht.signForm(roboform);
	Anoeht.executeForm(roboform);

	printHeader("RobotmyRequestForm Valid Test");
	RobotomyRequestForm	roboask("Tinker");
	std::cout << GREEN;
	Theona.signForm(roboask);
	Theona.executeForm(roboask);
}

void	testPresidentalPardonForm(Bureaucrat &Theona)
{
	Bureaucrat Anoeht("Anoeht", 15);

	printHeader("PresidentalPardonForm Invalid Test");
	PresidentalPardonForm	forgiveForm("Gul'dan");
	Anoeht.executeForm(forgiveForm);
	std::cout << GREEN;
	Anoeht.signForm(forgiveForm);
	Anoeht.executeForm(forgiveForm);

	printHeader("PresidentalPardonForm Valid Test");
	PresidentalPardonForm	pardonForm("Yurnero");
	std::cout << GREEN;
	Theona.signForm(pardonForm);
	Theona.executeForm(pardonForm);
}

void	askFileOpen()
{
	std::string	prompt = std::string(BOLD) + "Would you like to open" + tree_filename + "? (y / n) : ";
	std::string	answer = to_upper(get_safe_input(prompt));
	if (answer == "YES" || answer == "Y")
	{
		std::cout << readFile(tree_filename) << std::endl;
	}
}

void	askFileDelete()
{
	std::string prompt = std::string(BOLD) + "Would you like to delete " + tree_filename + "? (y / n) : ";
    std::string answer = to_upper(get_safe_input(prompt));

    if (answer == "YES" || answer == "Y")
	{
        if (std::remove(tree_filename.c_str()) == 0)
            std::cout << GREEN << "File deleted successfully.\n" << RESET;
		else
			std::perror(RED"Error deleting file");
	}
}

int	main()
{
	Bureaucrat	Theona("Theona", 1);
	testOCF();
	testShrubberyCreationForm(Theona);
	testRobotmyRequestForm(Theona);
	testPresidentalPardonForm(Theona);
	std::cout << "\n";
	askFileOpen();
	std::cout << "\n";
	askFileDelete();

}