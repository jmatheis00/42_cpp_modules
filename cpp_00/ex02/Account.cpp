/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:05:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/28 20:08:27 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << initial_deposit
			<< ";created" << std::endl;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << checkAmount()
			<< ";closed" << std::endl;
}

// locatime years since 1900
void Account::_displayTimestamp()
{
	time_t now;
	std::time(&now);

	tm *timeunit = localtime(&now);
	std::cout<<"["<< 1900 + timeunit->tm_year;
	if (timeunit->tm_mon < 10)
		std::cout << "0";
	std::cout << 1 + timeunit->tm_mon;
	if (timeunit->tm_mday < 10)
		std::cout << "0";
	std::cout << timeunit->tm_mday << "_";
	if (timeunit->tm_hour < 10)
		std::cout << "0";
	std::cout << timeunit->tm_hour;
	if (timeunit->tm_min < 10)
		std::cout << "0";
	std::cout << timeunit->tm_min;
	if (timeunit->tm_sec < 10)
		std::cout << "0";
	std::cout << timeunit->tm_sec << "] ";
}

int Account::getNbAccounts()
{
	return(_nbAccounts);
}

int Account::getTotalAmount()
{
	return(_totalAmount);
}

int Account::getNbDeposits()
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return(_totalNbWithdrawals);	
}

int Account::checkAmount( void ) const
{
	return(_amount);
}

// total numbers
void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout <<"accounts:" << getNbAccounts()
			<<";total:" << getTotalAmount()
			<<";deposits:" << getNbDeposits()
			<<";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit( int deposit )
{
	_nbDeposits = 1;
	_displayTimestamp();
	std::cout <<"index:" <<  _accountIndex
			<<";p_amount:" << checkAmount()
			<<";deposit:" << deposit
			<<";amount:" << checkAmount() + deposit
			<<";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout <<"index:" << _accountIndex
			<<";p_amount:" << checkAmount()
			<<";withdrawal:";
	if (withdrawal <= checkAmount())
	{
		_nbWithdrawals = 1;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << withdrawal
				<< ";amount:" << checkAmount()
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}

// for every index
void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout <<"index:" << _accountIndex
			<<";amount:" << checkAmount()
			<<";deposits:" << _nbDeposits
			<<";withdrawals:" << _nbWithdrawals << std::endl;
}
