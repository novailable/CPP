#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {(void)other;}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::sort(char **argv)
{
	std::vector<int>	vec;
	std::deque<int>		deq;

	try
	{
		vec = create_container<std::vector<int> >(argv);
		deq = create_container<std::deque<int> > (argv);
		if (check_container(vec))
			throw	std::logic_error("Already sorted!");
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << "\n";
		return ;
	}
	std::cout << "Before:\t" ;
	print_container(vec);
	std::cout << "\n";

	std::clock_t	start = std::clock();
	vec = ford_johnson(vec);
	std::clock_t	end = std::clock();

	std::cout << "After:\t";
	print_container(vec);
	std::cout << "\n";

    double vec_time = double(end - start) * 1000000.0 / CLOCKS_PER_SEC;

	start = std::clock();
	deq = ford_johnson(deq);
	end = std::clock();
	double deq_time = double(end - start) * 1000000.0 / CLOCKS_PER_SEC;


    std::cout << "Time to process a range of " << vec.size() << " elements with std::[vector] : " << vec_time << " us\n"
			<< "Time to process a range of " << deq.size() << " elements with std::[deque]  : " << deq_time << " us" << std::endl;
}