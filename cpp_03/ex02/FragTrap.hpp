/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:31:24 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:18:05 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#define RESET "\033[0m"	  /* Reset */
#define RED "\033[31m"	  /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */

// INHERITED FROM CLAPTRAP
// constructors & destructor
// constructor desctrucor and attack prints different messages
// uses attributes of ClapTrap
// new function: void guardGate();
class FragTrap : public ClapTrap
{
public:
	FragTrap(); // Default Constructor
	FragTrap(std::string name);
	FragTrap(const FragTrap &copyclass);		 // Copy Constructor
	FragTrap &operator=(const FragTrap &copyop); // copy assignment operator
	~FragTrap();								 // Destructor

	void highFivesGuys();
};

std::ostream &operator<<(std::ostream &os, const FragTrap &i);

#endif