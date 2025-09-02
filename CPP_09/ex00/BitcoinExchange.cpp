#include "BitcoinExchange.hpp"

Date::Date() : y(0), m(0), d(0) {};

Date::Date(const std::string &str)
{
	validate(str);
	sscanf(str.c_str(), "%d-%d-%d", &y, &m, &d);
}

bool	Date::operator<(const Date &other) const
{
	if (y != other.y)
		return (y < other.y);
	if (m != other.m)
		return (m < other.m);
	return (d < other.d);
}

bool	Date::operator==(const Date &other) const
{
	return (y == other.y && m == other.m && d == other.d);
}

bool	Date::operator!=(const Date &other) const
{
	return	(!(*this == other));
}

void	Date::validate(const std::string &str)
{
	int	yrs, mth, day;

	if (sscanf(str.c_str(), "%d-%d-%d", &yrs, &mth, &day) != 3)
		throw	std::invalid_argument("Date: invalid format");
	if (mth > 12 || mth < 1)
		throw	std::out_of_range("Date: month out of range");
	static const int	days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int dim = days_in_month[mth-1];
	if (mth == 2 && ((yrs % 4 == 0 && yrs % 100 != 0) || (yrs % 400 == 0)))
		dim = 29;
	if (day < 1 || day > dim)
		throw	std::out_of_range("Date: day out of range");
}

std::ostream	&operator<<(std::ostream &out, const Date &other)
{
	out << other.y << "-" << other.m << "-" << other.d;
	return (out);
}

BitcoinExchange::BitcoinExchange()
{
	this->read_file("data.csv", ',', &BitcoinExchange::set_db);
	if (_exdb.size() == 0)
		throw	std::underflow_error("Error: Database: 'data.csv' set up failure");
	std::cout << "\033[32m\033[1mDatabase: set up done\033[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_exdb = other._exdb;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &db_filename)
{
	read_file(db_filename, ',', &BitcoinExchange::set_db);
	if (_exdb.size() == 0)
		throw	std::underflow_error("Error: Database: '" + db_filename + "' set up failure");
	std::cout << "\033[32m\033[1mDatabase: set up done\033[0m" << std::endl;
}

void	BitcoinExchange::read_file(const std::string &filename, const char &delimeter, void (BitcoinExchange::*func)(const Date&, double))
{
	std::ifstream	file(filename.c_str());
	if (!file)
		throw	std::ios_base::failure("Error: failed to open file '" + filename + "'");
	std::string	line;

	std::getline(file, line);
	if (line.empty())
		throw	std::invalid_argument("Error: '" + filename + "' is empty!");
	if (line != "date,exchange_rate" && line != "date | value")
		std::cerr << "Error: bad input => " << line << std::endl;

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		std::string	date_str, value_str;
		std::istringstream	iss(line);
		try
		{
			std::getline(iss, date_str, delimeter);
			if (iss.eof())
				throw	std::invalid_argument("bad input => " + line);
			Date	date(date_str);

			double	value;
			if (!(iss >> value))
				throw	std::invalid_argument("invalid numeric value => " + line);
			if (!(iss >> std::ws).eof())
				throw	std::invalid_argument("bad input => " + line);
		
			(this->*func)(date, value);
		}
		catch(const std::exception& e)
		{
			std::string	err_msg = e.what();
			if (err_msg.find("Date: ") != std::string::npos)
				err_msg += " => " + date_str;
			
			std::cerr << "Error: " << err_msg << std::endl;
		}
	}
	file.close();
}

void	BitcoinExchange::set_db(const Date &date, double value)
{
	_exdb[date] = value;
}

void	BitcoinExchange::exchange(const std::string &filename)
{
	this->read_file(filename, '|', &BitcoinExchange::print_exchange);
}

void	BitcoinExchange::print_exchange(const Date &date, double value)
{
	if (value < 0)
		throw	std::out_of_range("not a positive number");
	if (value > 100)
		throw	std::out_of_range("too large a number");
	std::map<Date, double>::const_iterator	it = _exdb.lower_bound(date);
	if (it == _exdb.end() || it->first != date)
	{
		if (it != _exdb.begin())
			--it;
	}
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}
