/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:45:37 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/12 15:20:27 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	functionpointer[0] = &Harl::debug;
	functionpointer[1] = &Harl::info;
	functionpointer[2] = &Harl::warning;
	functionpointer[3] = &Harl::error;
}

Harl::~Harl()
{
	
}

void Harl::debug()
{
	std::cout << RED << "debug message: \n" << RESET \
	"I love having extra bacon for my "\
	"7XL-double-cheese-triple-pickle-special- ketchup burger. "\
	"I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << RED << "info message: \n" << RESET \
	"I cannot believe adding extra bacon costs more money. "\
	"You didn’t put enough bacon in my burger! "\
	"If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << RED << "warning message: \n" << RESET \
	"I think I deserve to have some extra bacon for free. "\
	"I’ve been coming for years whereas you started working here "\
	"since last month." << std::endl;
}

void Harl::error()
{
	std::cout << RED << "error message: \n" << RESET \
	"This is unacceptable! I want to speak to the manager now."\
	<< std::endl;
}

// this->* for calling the member function pointer
// on the current object instance (name of class declared in main)
// for accessing member function (debug, info, ...)
void Harl::complain(std::string level)
{
	int	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*functionpointer[i])();
			return ;
		}
		i++;
	}
	std::cout << "Please enter a valid level" << std::endl;
}