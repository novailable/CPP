#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>


int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int init_deposit) 
	: _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0) 
	{
		this->_accountIndex = _nbAccounts++;
		_totalAmount += init_deposit;
		_amount = init_deposit;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";amount:" << init_deposit << ";created" << std::endl;
	}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {return (_totalAmount);}

int	Account::getNbDeposits(void) {return (_totalNbDeposits);}

int	Account::getNbWithdrawals(void) {return (_totalNbWithdrawals);}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit ;
	_amount += deposit;
	std::cout << ";amount:" << _amount<< ";nb_deposists:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";" << std::endl;
	return (_amount);	
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	current = std::time(nullptr);
	std::tm* 	l_time = std::localtime(&current);
	std::cout << "[" 
			  << l_time->tm_year + 1900 
			  << std::setw(2) << std::setfill('0') << l_time->tm_mon + 1 
			  << std::setw(2) << std::setfill('0') << l_time->tm_mday << "_"
			  << std::setw(2) << std::setfill('0') << l_time->tm_hour
			  << std::setw(2) << std::setfill('0') << l_time->tm_min 
			  << std::setw(2) << std::setfill('0') << l_time->tm_sec
			  << "] ";
}
