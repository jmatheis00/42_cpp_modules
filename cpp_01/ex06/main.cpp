/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:48:12 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/12 15:32:06 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char *argc[])
{
	if (ac != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		exit (1);
	}
	Harl test;
	test.complain(argc[1]);
	return (0);
}