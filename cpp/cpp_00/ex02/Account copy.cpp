/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:05:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/01/31 15:54:56 by jmatheis         ###   ########.fr       */
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
	_amount = initial_deposit;
	std::cout <<"index:" << getNbAccounts();
	std::cout <<";amount:" << initial_deposit;
	std::cout << ";created";
	std::cout << std::endl;
	_totalAmount += initial_deposit;
	_nbAccounts++;
}

Account::~Account()
{
	_nbAccounts = 0;
	_displayTimestamp();
	std::cout <<"index:" << getNbAccounts();
	std::cout <<";amount:" << _amount;
	std::cout << ";closed";
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
	// std::cout <<";total:"<< getTotalAmount();
	// std::cout <<";deposits:"<< getNbDeposits();
	// std::cout <<";withdrawals:"<< getNbWithdrawals();
	std::cout << std::endl;
	_nbAccounts = 0;
	// _totalAmount = 0;
}

void Account::makeDeposit( int deposit )
{
	// _accountIndex = 0;
	// int amount;
	std::cout << deposit << '\t';
	_displayTimestamp();
	std::cout <<"index:" << getNbAccounts();
	// std::cout <<";p_amount:" << _amount;
	// std::cout <<";deposits:"<< deposit;
	// amount = _amount + deposit;
	// std::cout <<";amount:" << amount;
	// _amount = amount;
	// std::cout <<";nb_deposits:"<< _nbDeposits;
	std::cout << std::endl;
	_accountIndex++;
	_totalAmount = getTotalAmount();
	// _totalAmount += amount;
	_totalNbDeposits += _nbDeposits;
}

bool Account::makeWithdrawal( int withdrawal )
{
	// int newamount;
	_nbWithdrawals++; //???
	_nbAccounts = 0;
	std::cout << withdrawal << '\t';
	_displayTimestamp();
	std::cout <<"index:" << getNbAccounts();
	// std::cout <<";p_amount:" << _amount;
	// newamount = _amount - withdrawal;
	// if (newamount < 0)
	// 	std::cout <<";withdrawal:refused";
	// else
	// {
	// 	std::cout <<";withdrawal:" << withdrawal;
	// 	std::cout << ";amount:" << newamount;
	// 	std::cout << ";nb_withdrawals:" << _nbWithdrawals;
	// }
	std::cout <<std::endl;
	_totalNbWithdrawals += _nbWithdrawals;
	_totalAmount = getTotalAmount();
	// TOTAL AMOUNT - WITHDRAWALS THAT ARE NOT REFUSED
	// TAKE OLD AMOUNT
	_nbAccounts++;
	return (withdrawal);
}

int Account::checkAmount( void ) const
{
	int test = 2;
	return(test);
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout <<"index:" << getNbAccounts();
	// std::cout <<";amount:" << _amount;
	// std::cout <<";deposits:" << _totalNbDeposits;
	// std::cout<<";withdrawals:"<<_nbWithdrawals;
	std::cout << std::endl;
	_nbAccounts++;
}
