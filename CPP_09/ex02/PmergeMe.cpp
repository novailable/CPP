#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {(void)other;}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe() {}

std::size_t	PmergeMe::jacobsthal(std::size_t n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	std::size_t a = 0, b = 1;
	for (std::size_t i = 2; i <= n; ++i)
	{
		std::size_t c = b + 2 * a;
		a = b;
		b = c;
	}
	return (b);
}

std::vector<std::size_t>	PmergeMe::make_jacob_insertion_order(std::size_t m)
{
	std::vector<std::size_t> order;
	order.reserve(m);
	if (m == 0)
		return order;

	// Classic pattern: take blocks (J(k) ... J(k-1)+1) in descending order.
	// We adapt to 0-based indexing.
	std::vector<bool> used(m, false);

	std::size_t k = 3; // start from J(3)=3 gives first non-trivial block
	std::size_t prev = jacobsthal(2); // J(2)=1

	while (order.size() < m)
	{
		std::size_t jk = jacobsthal(k);
		if (jk > m)
			jk = m;

		// Insert indices: jk-1 down to prev (inclusive), skipping already used.
		for (std::size_t idx = jk; idx > prev; --idx)
		{
			std::size_t i = idx - 1; // convert to 0-based
			if (i < m && !used[i])
			{
				used[i] = true;
				order.push_back(i);
				if (order.size() == m)
					return order;
			}
		}

		prev = jacobsthal(k);
		if (prev >= m)
			break;
		++k;
	}

	// Fill any remaining indices in increasing order (safety / tail).
	for (std::size_t i = 0; i < m; ++i)
	{
		if (!used[i])
			order.push_back(i);
	}
	return order;
}

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