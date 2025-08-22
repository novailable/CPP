#include "Serializer.hpp"

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define CYAN		"\033[36m"
#define BOLD		"\033[1m"

int	main()
{
	Data	test = {1};

	std::cout << CYAN << "Original: \t" << RESET << &test << ", value: " << test.value << std::endl;
	uintptr_t raw = Serializer::serialize(&test);
	std::cout << CYAN << "Serialize: \t" << RESET << raw << std::endl;
	Data	*deserial = Serializer::deserialize(raw);
	std::cout << CYAN << "Deserialize: \t" << RESET << deserial << ", value: " << deserial->value << std::endl;

	if (deserial == &test)
		std::cout << BOLD << GREEN << "===== PASSSED =====" << std::endl;
	else
		std::cout << BOLD << RED << "IT'S NOT THE SAME!" << std::endl;
	
}