#include <iomanip>
#include <iostream>
#include <string>

int	main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Memory address of the string    : " << &str << std::endl;
	std::cout << "Memory address of the stringPTR : " << stringPTR << std::endl;
	std::cout << "Memory address of the stringREF : " << &stringREF << std::endl;
	std::cout << "\n";
	std::cout << "Value of the string : " << str << std::endl;
	std::cout << "Value of the string : " << *stringPTR << std::endl;
	std::cout << "Value of the string : " << stringREF << std::endl;

}