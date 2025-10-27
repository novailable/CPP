#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <deque>

class	PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();

		void static	sort(char **argv);

		template	<typename Container>
		static Container	create_container(char **array)
		{
			Container	container;
			for (int i = 0; array[i]; ++i)
			{
				std::stringstream	ss(array[i]);
				int	value;
	
				ss >> value;
				if (ss.fail() || !ss.eof() || value < 0)
					throw	std::invalid_argument("Error");
				container.push_back(value);
			}
			return (container);
		}

		template	<typename Container>
		static void		print_container(const Container &container)
		{
			std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
		}

		template	<typename	Container>
		static	bool	check_container(const Container &container)
		{
			if (container.empty())
				return (true);
			typename Container::const_iterator it = container.begin();
			typename Container::const_iterator next = it + 1;

			for (; next != container.end(); ++it, ++next)
				if (*next < *it)
					return false;
			return true;
		}

		template	<typename Container>
		static Container	ford_johnson(Container &arr)
		{
			int	n;

			n = arr.size();
			if (n <= 1 )
				return (arr);

			Container	small, large;
			
			for (int i = 0; i + 1 < n; i += 2)
			{
				if (arr[i] < arr[i + 1])
				{
					small.push_back(arr[i]);
					large.push_back(arr[i + 1]);
				}
				else
				{
					small.push_back(arr[i + 1]);
					large.push_back(arr[i]);
				}
			}
			if (n % 2 != 0)
				small.push_back(arr[n - 1]);
			
			large = ford_johnson(large);

			for (int i = 0; i < (int)small.size(); ++i)
			{
				int left = 0, right = large.size();
				while (left < right)
				{
					int mid = left + (right - left) / 2;
					if (small[i] < large[mid])
						right = mid;
					else
						left = mid + 1;
				}
				large.insert(large.begin() + left, small[i]);
			}
			return (large);
		}
};

#endif
