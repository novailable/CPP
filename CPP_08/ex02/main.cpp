#include "MutantStack.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>

template <typename Container, typename T>
Container	create_container(T &array)
{
	int	size = sizeof(array) / sizeof(array[0]);
	return (Container(array, array + size));
}

template <typename T>
void	print_container(T container)
{
	typedef typename T::value_type	value_type;

	std::copy(container.begin(), container.end(), std::ostream_iterator<value_type>(std::cout, " "));
	std::cout << std::endl;
}


int	main()
{
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
		print_container(mstack);
		std::string	test[] = {"_apple", "_banana", "_cocomelon"};

		typedef MutantStack<std::string>	Mutant;
		Mutant	mutant= create_container<Mutant>(test);
		print_container(mutant);
		const Mutant	&const_mutant = mutant;
		std::cout << "const_mutant.end():  " << *--const_mutant.end() << std::endl;
	}

	{
		std::list<int>	lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		// std::stack<int> s(mstack);
		print_container(lst);

		std::string	test[] = {"_apple", "_banana", "_cocomelon"};

		typedef std::list<std::string>	Lst_str;
		Lst_str	lststr = create_container<Lst_str>(test);
		print_container(lststr);
		const Lst_str	&const_lststr = lststr;
		std::cout << "const_mutant.end():  " << *--const_lststr.end() << std::endl;
	}
}