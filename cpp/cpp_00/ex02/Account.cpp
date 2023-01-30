/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:05:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/01/30 16:17:39 by jmatheis         ###   ########.fr       */
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
	initial_deposit = 0;
}

Account::~Account()
{

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
	if (&getNbAccounts != 0)
	{
		std::cout <<"accounts:" << &getNbAccounts;
		std::cout <<";total:"<< &getTotalAmount;
		std::cout <<";deposits:"<< &getNbDeposits;
		std::cout <<";withdrawals:"<< &getNbWithdrawals <<std::endl;
		
	}
	// ints_t
	// accounts_t::iterator
}

void Account::makeDeposit( int deposit )
{
	_nbDeposits = deposit;
	std::cout<< deposit << std::endl;
	// _accountIndex++;
	// if (!deposit)
	// 	deposit = getNbDeposits();
	// std::cout << "TEST" << acc_end <<std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	int i = 0;
	if (withdrawal != 0)
		i  = 1;
	_nbWithdrawals = withdrawal;
	std::cout << withdrawal<<std::endl;
	return (i);
}

int Account::checkAmount( void ) const
{
	// Account::t(accounts_t);
	int test = 2;
	return(test);
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout <<"index:";
	if (_nbDeposits || _nbWithdrawals)
	{
		std::cout<<";p_amount:";
	}
	else
	{
		std::cout <<";amount:";
	}
	std::cout <<";deposits:"<< _nbDeposits;
	std::cout<<";withdrawals:"<<_nbWithdrawals;
	if ( _nbWithdrawals > 0)
	{
		std::cout<<";amount:";
		std::cout<<"nb_withdrawals";
	}
	std::cout << std::endl;
}
