/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:45:37 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/12 15:28:05 by jmatheis         ###   ########.fr       */
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
	<< "I love having extra bacon for my "\
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

// if case 0 is correct --> everything is correct until "break ;"
void Harl::complain(std::string level)
{
	int	i = 0;
	while (i < 4 && level.compare(levels[i]))
		i++;
	switch(i)
	{
		case 0 : (this->*functionpointer[0])();
		case 1 : (this->*functionpointer[1])();
		case 2 : (this->*functionpointer[2])();
		case 3 : (this->*functionpointer[3])(); break ;
		default: std::cout << "Please enter a valid level" << std::endl;
	}
}