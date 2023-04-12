/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:48:12 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/12 15:23:21 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char *argc[])
{
	if (ac != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (1);
	}
	Harl test;
	std::cout << GREEN << "TEST WITH INPUT: " << argc[1] << RESET << std::endl;
	test.complain(argc[1]);
	return (0);
}