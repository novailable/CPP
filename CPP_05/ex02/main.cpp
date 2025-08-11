#include "Form.hpp"
#include "Bureaucrat.hpp"

void	printHeader(const std::string &title)
{
	std::cout << BOLD << CYAN << "\n=== " << title << " ===\n" << RESET;
}

void	testConstructor()
{
	printHeader("Form Constructor Test");
	try
	{
		AForm	form;
		std::cout << GREEN << form << RESET << "\n";
		AForm	form1("Form", 30);
		std::cout << GREEN << form1 << RESET << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Form Constructor: " << e.what() << RESET << "\n";
	}
	printHeader("Copy Constructor and Assignment Test");
	AForm original("OrgForm", 75);
	Bureaucrat	cat("Cat", 34);
	std::cout << GREEN << cat << RESET << "\n";
	original.beSigned(cat);
	AForm copy(original);
	AForm assigned("AssignForm", 25);
	std::cout << GREEN << assigned << RESET << "\n";
	assigned = original;
	std::cout << YELLOW << "Original: " << RESET << original << "\n";
	std::cout << YELLOW << "Copy: " << RESET << copy << "\n";
	std::cout << YELLOW << "Assigned: " << RESET << assigned << "\n";
	printHeader("Invalid Construction Test");
	try
	{
		AForm	f1("f1", 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << RESET << "\n";
	}
	try
	{
		AForm	f11("f11", 151);	
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << RESET << "\n";
	}
}

void	testSign()
{
	printHeader("Form Sign Test");
	Bureaucrat	bureau("Theona", 12);
	try
	{
		AForm	form2("Form2", 30);
		std::cout << GREEN << form2 << "\n";
		std::cout << bureau << "\n";
		bureau.signForm(form2);
		std::cout << form2 << RESET << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Form Constructor: " << e.what() << RESET << "\n";
	}
	printHeader("Invalid Sign Test");
	AForm	f2("f2", 10);
	std::cout << GREEN << f2 << RESET << "\n";
	std::cout << GREEN << bureau << RED << "\n";
	bureau.signForm(f2);
	std::cout << RESET << std::endl;

}

int	main()
{
	testConstructor();
	testSign();
}