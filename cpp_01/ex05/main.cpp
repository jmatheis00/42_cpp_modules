/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:48:12 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:13:01 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// FUNCTIONPOINTERS:
// way to select a function
// to execute based on run-time values
int main(void)
{
	Harl test;
	std::cout << GREEN << "INVALID TEST" << RESET << std::endl;
	test.complain("INVALID");
	std::cout << GREEN << "DEBUG TEST" << RESET << std::endl;
	test.complain("DEBUG");
	std::cout << GREEN << "INFO TEST" << RESET << std::endl;
	test.complain("INFO");
	std::cout << GREEN << "WARNING TEST" << RESET << std::endl;
	test.complain("WARNING");
	std::cout << GREEN << "ERROR TEST" << RESET << std::endl;
	test.complain("ERROR");
	return (0);
}