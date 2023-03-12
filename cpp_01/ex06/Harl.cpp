/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:45:37 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/12 15:08:11 by jmatheis         ###   ########.fr       */
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
	std::cout << "debug message: \n"\
	"I love having extra bacon for my "\
	"7XL-double-cheese-triple-pickle-special- ketchup burger. "\
	"I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "info message: \n"\
	"I cannot believe adding extra bacon costs more money. "\
	"You didn’t put enough bacon in my burger! "\
	"If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "warning message: \n"\
	"I think I deserve to have some extra bacon for free. "\
	"I’ve been coming for years whereas you started working here "\
	"since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "error message: \n"\
	"This is unacceptable! I want to speak to the manager now."\
	<< std::endl;
}

void Harl::complain(std::string level)
{
	int	i = 0;
	while (i < 4 && level.compare(levels[i]))
		i++;
	if (level.compare(levels[i]))
		std::cout << "Please enter a valid level" << std::endl;
	else
		(this->*functionpointer[i])();
}