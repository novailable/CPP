#include "Form.hpp"
#include "Bureaucrat.hpp"

void	print_header(const std::string &title)
{
	std::cout << BOLD << CYAN << "\n=== " << title << " ===\n" << RESET;
}

void	testConstructor()
{
	print_header("Form Constructor Test");
	try
	{
		Form	form;
		std::cout << GREEN << form << RESET << "\n";
		Form	form1("Form", 30);
		std::cout << GREEN << form1 << RESET << "\n";
		Form	form2("Form2", 30, 40);
		std::cout << GREEN << form1 << RESET << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Form Constructor: " << e.what() << RESET << "\n";
	}
	print_header("Copy Constructor and Assignment Test");
	Form original("OrgForm", 75, 80);
	Bureaucrat	cat("Cat", 34);
	std::cout << GREEN << cat << RESET << "\n";
	original.beSigned(cat);
	Form copy(original);
	Form assigned("AssignForm", 25, 80);
	std::cout << GREEN << assigned << RESET << "\n";
	assigned = original;
	std::cout << YELLOW << "Original: " << RESET << original << "\n";
	std::cout << YELLOW << "Copy: " << RESET << copy << "\n";
	std::cout << YELLOW << "Assigned: " << RESET << assigned << "\n";
	print_header("Invalid Construction Test");
	try
	{
		std::cout << YELLOW << "creating form with zero required grade to sign" << RESET << "\n";
		Form	f1("f1", 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << RESET << "\n";
	}
	try
	{
		std::cout << YELLOW << "creating form with required grade 151 to sign" << RESET << "\n";
		Form	f11("f11", 151);	
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << RESET << "\n";
	}
	try
	{
		std::cout << YELLOW << "creating form with zero required grade to execute" << RESET << "\n";
		Form	f12("f12", 42, 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << RESET << "\n";
	}
	try
	{
		std::cout << YELLOW << "creating form with required grade 151 to execute" << RESET << "\n";
		Form	f111("f111", 42, 151);	
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << RESET << "\n";
	}
}

void	testSign()
{
	print_header("Form Sign Test");
	Bureaucrat	Theona("Theona", 12);
	Form	form2("Form2", 30);
	try
	{
		
		std::cout << GREEN << form2 << "\n";
		std::cout << Theona << "\n";
		Theona.signForm(form2);
		std::cout << form2 << RESET << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Form Constructor: " << e.what() << RESET << "\n";
	}
	print_header("Invalid Sign Test");
	Form	f2("f2", 10);
	std::cout << GREEN << f2 << RESET << "\n";
	std::cout << GREEN << Theona << RED << "\n";
	Theona.signForm(f2);
	Theona.signForm(form2);
	std::cout << RESET << std::endl;

}

int	main()
{
	testConstructor();
	testSign();
}