#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other;}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other) 
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

static bool isFloatLiteral(const std::string &s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return true;
	if (!s.empty() && s[s.size() - 1] != 'f')
		return false;
	char	*end;
	errno = 0;
	std::strtod(s.c_str(), &end);
	return (*(end) == 'f' && *(end + 1) == '\0');
}

static bool isDoubleLiteral(const std::string &s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return true;
	char	*end;
	errno = 0;
	std::strtod(s.c_str(), &end);
	return *end == '\0';
}

static void printChar(double value)
{
	if (std::isnan(value) || std::isinf(value) ||
		value < std::numeric_limits<char>::min() ||
		value > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	char c = static_cast<char>(value);
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void printInt(double value)
{
	if (std::isnan(value) || std::isinf(value) ||
		value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	int i = static_cast<int>(value);
	std::cout << "int: " << i << std::endl;
}

static void	printFloat(double value)
{
	float	f = static_cast<float>(value);
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf";
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inff" : "-inff");
	else
		std::cout << std::fixed << f << "f";
	std::cout << std::endl;
}

static void	printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan";
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf");
	else
		std::cout << std::fixed << value;
	std::cout << std::endl;
}

void	ScalarConverter::convert(const std::string &input)
{
	double	value = 0.0;

	if (input.size() == 1)
		value = static_cast<double>(input[0]);
	else if (isFloatLiteral(input)) 
	{
		if (input == "nanf") value = std::numeric_limits<float>::quiet_NaN();
		else if (input == "+inff") value = std::numeric_limits<float>::infinity();
		else if (input == "-inff") value = -std::numeric_limits<float>::infinity();
		else value = (std::atof(input.c_str()));
	}
	else if (isDoubleLiteral(input)) 
	{
		if (input == "nan") value = std::numeric_limits<double>::quiet_NaN();
		else if (input == "+inf") value = std::numeric_limits<double>::infinity();
		else if (input == "-inf") value = -std::numeric_limits<double>::infinity();
		else value = std::atof(input.c_str());
	}
	else
	{
		std::cerr << "Error: invalid literal" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
