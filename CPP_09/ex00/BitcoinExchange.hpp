#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdio>

struct	Date
{
	int	y;
	int	m;
	int	d;

	Date();
	Date(const std::string &str);
	bool	operator<(const Date &other) const;
	bool	operator==(const Date &other) const;
	bool	operator!=(const Date &other) const;
	static void	validate(const std::string &str);
};

std::ostream	&operator<<(std::ostream &out, const Date &date);

class	BitcoinExchange
{
	private:
		std::map<Date, double>	_exdb;
		void	set_db(const Date &Date, double value);
		void	print_exchange(const Date& Date, double value);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange(const std::string &db_filename);

		void	read_file(const std::string &filename, const char &delimeter, void (BitcoinExchange::*func)(const Date&, double));
		void	exchange(const std::string &filename);
};

#endif