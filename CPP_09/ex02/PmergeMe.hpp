#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class	PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();

		void static	PmergeMe::sort(char **argv);
};

#endif
