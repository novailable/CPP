#include "Array.hpp"

#include <string>
#include <iostream>

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define CYAN		"\033[36m"
#define BOLD		"\033[1m"

void	result(bool result)
{
	std::cout << BOLD << (result ? GREEN"===Pass" : RED"===Fail") << "===" << RESET << std::endl;
}

void	print_header(const std::string &title)
{
	std::cout << BOLD << CYAN << "\n=== " << title << " ===\n" << RESET;
}

template <typename T>
bool	testOCF(const Array<T> &array, std::string type)
{
	print_header(type + " OCF Tests");
	try
	{
		Array<T>	one;
		std::cout << "one: " << one.string() << std::endl;
		Array<T>	two(array);
		std::cout << "two: " << two.string() << std::endl;
		Array<T>	three;
		
		std::cout << "three: " << three.string() << std::endl;
		three = array;
		three[0] = three[0];
		if (&three[0] == &array[0])
			return (false);
		std::cout << "three = array, three: " << three.string() << std::endl;
		return (true);
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << std::endl;
		return (false);
	}
}

template <typename T>
bool	testIndexing(Array<T> array, std::string type)
{
	print_header(type + " Indexing Tests");
	const Array<T>	one(2);
	Array<T>	two;
	try
	{
		if (array.size())
			std::cout << "Array[0]: " << array[0] \
					<< ", Array[" << array.size() - 1 << "]: " << array[array.size() - 1]  << std::endl;
		std::cout << YELLOW << "const " << RESET << "one: " << one.string() << std::endl;
		std::cout << YELLOW << "const " << RESET "one[1]: " << one[1] << std::endl;
		std::cout << "two: " << two.string() << std::endl;
		two[0];
	}
	catch (const std::exception &e)
	{
		std::cerr << "two[0]: " << RED << e.what() << RESET << std::endl;
		return (true);
	}
	return (false);
}

int	main()
{
	Array<std::string> str_array(4);
	str_array[0] = "apple";
	str_array[1] = "banana";
	str_array[2] = "coconut";
	str_array[3] = "durian";

	Array<int> int_array(4);
	for (std::size_t i = 0; i < int_array.size(); ++i)
		int_array[i] = i + 1;

	result(testOCF(str_array, "string"));
	result(testOCF(int_array, "int"));

	result(testIndexing(str_array, "string"));
	result(testIndexing(int_array, "int"));

	Array<std::string> str(3);
	
}