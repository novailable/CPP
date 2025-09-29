#include <vector>
#include <iostream>

int main()
{
	std::vector<std::string> some;

	some.push_back("ok");

	std::cout << "1 mem add: " << &some[0] << std::endl;

	std::vector<std::string> other = some;

	std::cout << "2 mem add: " << &other[0] << std::endl;

}

