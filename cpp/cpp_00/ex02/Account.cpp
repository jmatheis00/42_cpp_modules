/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:05:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/01/31 19:37:07 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp()
{
	time_t now = NULL;
	std::time(&now);

	tm *ltm = localtime(&now);
	std::cout<<"["<< 1900 + ltm->tm_year;
	if (ltm->tm_mon < 10)
		std::cout << "0";
	std::cout << 1 + ltm->tm_mon;
	if (ltm->tm_mday < 10)
		std::cout << "0";
	std::cout << ltm->tm_mday << "_";
	if (ltm->tm_hour < 10)
		std::cout << "0";
	std::cout << ltm->tm_hour;
	if (ltm->tm_min < 10)
		std::cout << "0";
	std::cout << ltm->tm_min;
	if (ltm->tm_sec < 10)
		std::cout << "0";
	std::cout << ltm->tm_sec << "] ";
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	std::cout <<"index:" << getNbAccounts();
	std::cout <<";amount:" << initial_deposit;
	std::cout <<";created";
	std::cout << std::endl;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbAccounts++;
}

Account::~Account()
{
	if (_nbAccounts == 8)
		_nbAccounts = 0;
	_displayTimestamp();
	std::cout <<"index:" << getNbAccounts();
	std::cout <<";amount:" << _amount;
	std::cout <<";closed";
	std::cout << std::endl;
	_nbAccounts++;
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

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout <<"accounts:" << getNbAccounts();
	std::cout <<";total:" << getTotalAmount();
	std::cout <<";deposits:" << getNbDeposits();
	std::cout <<";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
	_nbAccounts = 0;
}

void Account::makeDeposit( int deposit )
{
	if (_nbAccounts == 8)
		_nbAccounts = 0;
	_nbDeposits = 1;
	int	currentamount = _amount;
	_displayTimestamp();
	std::cout <<"index:" <<  getNbAccounts();
	std::cout <<";p_amount:" << currentamount;
	std::cout <<";deposit:" << deposit;
	std::cout <<";amount:" << currentamount + deposit;
	std::cout <<";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbAccounts++;
}

bool Account::makeWithdrawal( int withdrawal )
{
	int	currentamount = _amount;
	if (_nbAccounts == 8)
		_nbAccounts = 0;
	_displayTimestamp();
	std::cout <<"index:" << getNbAccounts();
	std::cout <<";p_amount:" << _amount;
	std::cout <<";withdrawal:";
	if (withdrawal > currentamount)
		std::cout <<"refused";
	else
	{
		_nbWithdrawals = 1;
		std::cout << withdrawal;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << ";amount:" << currentamount - withdrawal;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals;
		_totalNbWithdrawals++;
	}
	std::cout <<std::endl;
	_nbAccounts++;
	return (withdrawal);
}

int Account::checkAmount( void ) const
{
	int test = 2;
	// _nbAccounts++;
	return(test);
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	int	currentamount = _amount;
	std::cout <<"index:" << getNbAccounts();
	std::cout <<";amount:" << currentamount;
	std::cout <<";deposits:" << _nbDeposits;
	std::cout <<";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	_nbAccounts++;
}
