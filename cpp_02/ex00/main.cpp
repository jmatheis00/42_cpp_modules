/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:20:59 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/24 08:16:36 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Copy Constructor:
// initializing a previously uninitialized object
// frome some other object's data
// Copy Assignment Operator
// replacing data of a previously initialized
// object with some other object's data
int main(void)
{
    Fixed a;

    // Calls Copy Constructor
    Fixed b(a);

    Fixed c;

    // Calls Copy Assignment Operator
    c = b; 

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return (0);
}