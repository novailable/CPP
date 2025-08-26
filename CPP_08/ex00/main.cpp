#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <typeinfo>
#include <iterator>
#include "easyfind.hpp"

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

void	print_error(const std::string &msg)
{
	std::cerr << RED << msg << RESET << std::endl;
}

template <typename T>
void	print_container(T container)
{
	std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

template <typename Container, typename T>
Container	create_container(T &array)
{
	if (!array[0])
		return	Container();
	int	size = sizeof(array) / sizeof(array[0]);
	return (Container(array, array + size));
}

template <typename Iterator, typename Container>
bool	test_easyfind(Container &container, int find_value)
{
	Iterator	it;
	std::cout << "\n" << "find '" << find_value << "': ";
	try
	{
		it = ::easyfind(container, find_value);
		std::cout << "index: " << std::distance(container.begin(), it) << std::endl;
	}
	catch(const std::exception& e)
	{
		print_error(e.what());
		return (typeid(e) == typeid(std::out_of_range));
	}
	return (true);
}

template <typename Container, typename T_array>
bool	test_container(T_array &array, std::string type, int find_value)
{
	try
	{
		print_header(type + " test");
		Container	container = create_container<Container>(array);
		
		std::cout << YELLOW << type << RESET << "\t: numbers: ";
		print_container(container);
		
		std::cout << CYAN << "non-const: " << RESET;
		bool	non_const = test_easyfind<typename Container::iterator>(container, find_value);
		const Container &ccontainer = container;
		std::cout << CYAN << "const: " << RESET;
		bool const_test = test_easyfind<typename Container::const_iterator>(ccontainer, find_value);
		return (non_const && const_test);
	}
	catch(const std::exception &e)
	{
		print_error(e.what());
		return (false);
	}
}

int	main()
{
	int	numbers[] = {1, 2, 3, 4};
	result(test_container<std::vector<int> >(numbers, "vector", 1));
	result(test_container<std::deque<int> >(numbers, "deque", 5));
	result(test_container<std::list<int> >(numbers, "list", 3));
}