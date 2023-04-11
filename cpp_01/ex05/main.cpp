/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:48:12 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/11 15:55:45 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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