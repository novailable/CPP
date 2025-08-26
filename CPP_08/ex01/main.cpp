#include <iostream>
#include <deque>
#include <list>
#include <typeinfo>
#include "Span.hpp"

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

void	print_color(const std::string &title, const std::string color)
{
	std::cout << color << title << RESET;
}

void	print_error(const std::string &msg)
{
	std::cerr << RED << msg << RESET << std::endl;
}

template <typename Container, typename T>
Container	create_container(T &array)
{
	int	size = sizeof(array) / sizeof(array[0]);
	return (Container(array, array + size));
}

bool	test_OCF(Span &span)
{
	print_header("OCF Test");
	try
	{
		print_color("span\t: ", YELLOW);
		span.print();
		Span	one;
		print_color("one\t: ", YELLOW), one.print();
		Span	two(span);
		print_color("two(span), two\t: ", YELLOW), two.print();
		one = span;
		print_color("one = span, one\t: ", YELLOW), one.print();
		if (&one == &span)
			return (false);
		std::cout << "one.addNumber\t: ";
		one.addNumber(1431);
	}
	catch(const std::exception &e)
	{
		print_error(e.what());
		return (typeid(e) == typeid(std::overflow_error));
	}
	return (true);
}

bool	test_Span_Constructor()
{
	print_header("Span Constructor Test");
	try
	{
		int	array[] = {4, 2, 7};
		std::vector<int>	vec = create_container<std::vector<int> >(array);
		print_color("vector\t\t: ", YELLOW), print_container(vec);
		Span	one(3, vec);
		print_color("one(3, vec)\t: ", RESET), one.print();

		std::deque<int>	dque = create_container<std::deque<int> >(array);
		print_color("\ndeque\t\t: ", YELLOW), print_container(dque);
		Span	two(3, dque);
		print_color("two(3, dque)\t: ", RESET), two.print();

		std::list<int>	lst = create_container<std::list<int> >(array);
		print_color("\nlist\t\t: ", YELLOW), print_container(lst);
		Span	three(11, lst);
		print_color("three(11, lst)\t: ", RESET), three.print();
		
		try
		{
			std::list<int>	f_lst = create_container<std::list<int> >(array);
			print_color("\nforward-list\t: ", YELLOW), print_container(f_lst);
			print_color("four(2, f_lst)\t: ", RESET);
			Span	four(2, f_lst);
			four.print();
		}
		catch(const std::exception& e)
		{		
			print_error(e.what());
			if (typeid(e) != typeid(std::overflow_error))
				return (false);
		}
		std::cout << "\nthree.addNumber(lst): ";
		three.addNumber(lst);
		three.print();

		std::cout << "three.addNumber(vec.begin() + 1, vec.end()): ";
		three.addNumber(vec.begin() + 1, vec.end());
		three.print();

	}
	catch(const std::exception &e)
	{
		print_error(e.what());
		return (typeid(e) == typeid(std::overflow_error));
	}
	return (true);
}

bool	test_Span()
{
	bool	state = true;
	try
	{
		print_header("Longest/Shortest test");
		Span	one(100);
		one.addNumber(std::numeric_limits<int>::max());
		one.addNumber(std::numeric_limits<int>::min());
		std::vector<int> bigNumbers;
        for(int i = 0; i < 98; ++i)
            bigNumbers.push_back(i + i);
		one.addNumber(bigNumbers.begin(), bigNumbers.end());
		print_color("one\t: ", YELLOW), one.print();
		
		std::cout << "one.shortestSpan()\t: " << one.shortestSpan() << std::endl;
		std::cout << "one.longestSpan()\t: " << one.longestSpan() << std::endl;

		Span	two(1);
		two.addNumber(1);
		print_color("\ntwo\t: ", YELLOW), two.print();

		std::cout << "two.shortestSpan()\t: ";
		try
		{
			two.shortestSpan();
		}
		catch(const std::exception& e)
		{
			print_error(e.what());
			state = (typeid(e) == typeid(std::underflow_error));
		}
		std::cout << "two.longestSpan()\t: ";
		try
		{
			two.longestSpan();
		}
		catch(const std::exception& e)
		{
			print_error(e.what());
			state = (typeid(e) == typeid(std::underflow_error));
		}
		return (state);
	}
	catch(const std::exception& e)
	{
		print_error(e.what());
		return (false);
	}
	
}
int	main()
{
	Span	og(3);
	og.addNumber(3);
	og.addNumber(5);
	og.addNumber(7); 
	result(test_OCF(og));
	result(test_Span_Constructor());
	result(test_Span());
}
