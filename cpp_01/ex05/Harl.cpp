/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:45:37 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/09 19:34:44 by jmatheis         ###   ########.fr       */
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
}

Harl::~Harl()
{
	
}

void Harl::debug()
{
	std::cout << "debug message" << std::endl;
}

void Harl::info()
{
	std::cout << "info message" << std::endl;
}

void Harl::warning()
{
	std::cout << "warning message" << std::endl;
}

void Harl::error()
{
	std::cout << "error message" << std::endl;
}

void Harl::complain(std::string level)
{
	functionpointer[0] = &Harl::debug;
	functionpointer[1] = &Harl::info;
	functionpointer[2] = &Harl::warning;
	functionpointer[3] = &Harl::error;

	// std::cout << &functionpointer[0] << std::endl;
	// std::cout << &functionpointer[1] << std::endl;
	// std::cout << &functionpointer[2] << std::endl;
	// std::cout << &functionpointer[3] << std::endl;
	int	i = 0;
	while (i < 4 && level.compare(levels[i]))
	{
		i++;
	}
	(this->*functionpointer[i])();
	// for (int i = 0; i < 4 && level != &functionpointer[i]; i++)
	// {
		
	// }
	// std::cout << (this->*ptr)() << std::endl;
	
}