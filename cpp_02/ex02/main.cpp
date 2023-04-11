/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:20:59 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/11 17:25:35 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << GREEN "\nSTARTING VALUES" RESET << std::endl;
    std::cout << "a:\t" << a << std::endl;
    std::cout << "b:\t" << b << std::endl;

    std::cout << GREEN "\nComparison Operators" RESET << std::endl;
    std::cout << "a is smaller than b:\t" << (a < b) << std::endl;
    std::cout << "a is bigger than b:\t" << (a > b) << std::endl;
    std::cout << "a is equal to b:\t" << (a == b) << std::endl;
    std::cout << "a is unequal to b:\t" << (a != b) << std::endl;

    std::cout << GREEN "\nArithmetic Operators" RESET << std::endl;
    std::cout << "Multiplication:\t" << (a * b) << std::endl;
    std::cout << "Division:\t" << (a / b) << std::endl;
    std::cout << "Addition:\t" << (a + b) << std::endl;
    std::cout << "Subtraction:\t" << (a - b) << std::endl;

    std::cout << GREEN "\nPre- and Post- crement Operators" RESET << std::endl;  
    std::cout << "a:\t\t\t" << a << std::endl;
    std::cout << "a pre-incremented:\t" << ++a << std::endl;
    std::cout << "a:\t\t\t" << a << std::endl;
    std::cout << "a post-incremented:\t" << a++ << std::endl;
    std::cout << "a:\t\t\t" << a << std::endl;

    std::cout << GREEN "\nMember Functions" RESET << std::endl;
    std::cout << "Max:\t" << Fixed::max( a, b ) << std::endl;
    std::cout << "Min:\t" << Fixed::min( a, b ) << std::endl;

    return (0);
}