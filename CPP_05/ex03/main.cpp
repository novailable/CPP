#include <sstream>
#include <fstream>
#include <string>

#include "Intern.hpp"

std::string	tree_filename;

void	printError(std::string msg,const std::exception &e)
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

void	testShrubberyCreationForm(Bureaucrat &Theona, AForm *form)
{
	Bureaucrat	Anoeth("Anoeth", 140);

	printHeader("Shrubbery Form Invalid Test");
	Anoeth.executeForm(*form);
	std::cout << GREEN;
	Anoeth.signForm(*form);
	Anoeth.executeForm(*form);

	printHeader("Shrubbery Form Valid Test");
	std::cout << GREEN;
	Theona.executeForm(*form);
	std::cout << YELLOW;
	tree_filename = static_cast<ShrubberyCreationForm*>(form)->get_filename();
	
	std::cout << tree_filename << " created" << RESET << std::endl;
}

void	testRobotmyRequestForm(Bureaucrat &Theona, AForm *form)
{
	Bureaucrat Anoeht("Anoeht", 60);

	printHeader("RobotmyRequestForm Invalid Test");
	Anoeht.executeForm(*form);
	std::cout << GREEN;
	Anoeht.signForm(*form);
	Anoeht.executeForm(*form);

	printHeader("RobotmyRequestForm Valid Test");
	std::cout << GREEN;
	Theona.executeForm(*form);
}

void	testPresidentalPardonForm(Bureaucrat &Theona, AForm *form)
{
	Bureaucrat Anoeht("Anoeht", 15);

	printHeader("PresidentalPardonForm Invalid Test");
	Anoeht.executeForm(*form);
	std::cout << GREEN;
	Anoeht.signForm(*form);
	Anoeht.executeForm(*form);

	printHeader("PresidentalPardonForm Valid Test");
	std::cout << GREEN;
	Theona.executeForm(*form);
}

void	askFileOpen()
{
	std::string	prompt = std::string(BOLD) + "Would you like to open '" + tree_filename + "'? (y / n) : ";
	std::string	answer = to_upper(get_safe_input(prompt));
	if (answer == "YES" || answer == "Y")
	{
		std::cout << readFile(tree_filename) << std::endl;
	}
}

void	askFileDelete()
{
	std::string prompt = std::string(BOLD) + "Would you like to delete '" + tree_filename + "'? (y / n) : ";
	
    std::string answer = to_upper(get_safe_input(prompt));
	std::cout << RESET;
    if (answer == "YES" || answer == "Y")
	{
        if (std::remove(tree_filename.c_str()) == 0)
            std::cout << GREEN << "File deleted successfully.\n" << RESET;
		else
			std::perror(RED"Error deleting file");
	}
}

void	testIntern(Bureaucrat &Theona)
{
	printHeader("Invalid Intern Test");
	Intern	someRandomIntern;
	try
	{
		someRandomIntern.makeForm("cooking form", "Brown Bear");
	}
	catch(const std::exception& e)
	{
		printError("Intern Error: ", e);
	}

	printHeader("Valid Intern Test");
	std::cout << GREEN;
	AForm	*shrubbery = someRandomIntern.makeForm("shrubbery creation", "Brown Bear");
	AForm	*roboto = someRandomIntern.makeForm("robotomy request", "White Bear");
	AForm	*pardon = someRandomIntern.makeForm("presidential pardon", "Black Bear");
	std::cout << RESET;
	testShrubberyCreationForm(Theona, shrubbery);
	testRobotmyRequestForm(Theona, roboto);
	testPresidentalPardonForm(Theona, pardon);

	delete	shrubbery;
	delete	roboto;
	delete	pardon;
}

int	main()
{
	Bureaucrat	Theona("Theona", 1);
	testIntern(Theona);
	std::cout << "\n";
	askFileOpen();
	std::cout << "\n";
	askFileDelete();
}