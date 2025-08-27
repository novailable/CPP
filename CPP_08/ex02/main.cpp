#include "MutantStack.hpp"

#include <iostream>
#include <string>
#include <iterator>

template <typename Container, typename T>
Container	create_container(T &array)
{
	int	size = sizeof(array) / sizeof(array[0]);
	return (Container(array, array + size));
}

template <typename T>
void	print_container(T container)
{
	typedef typename T::value_type value_type;
	std::copy(container.begin(), container.end(), std::ostream_iterator<value_type>(std::cout, " "));
	std::cout << std::endl;
}

int	main()
{
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::string	test[] = {"_apple", "_banana", "_cocomelon"};

	typedef MutantStack<std::string>	Mutant;
	Mutant	mutant= create_container<MutantStack<std::string> >(test);
	print_container(mutant);
	const Mutant	&const_mutant = mutant;
	std::cout << "const_mutant.end():  " << *--const_mutant.end() << std::endl;
}