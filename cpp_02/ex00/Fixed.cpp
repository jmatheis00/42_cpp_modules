/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:11:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/22 17:02:09 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractbits_ = 8;

Fixed::Fixed() : fixedval_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copyclass)
{
	std::cout << "Copy constructor called" << std::endl;
	Fixed::operator= (copyclass);
}

Fixed& Fixed::operator= (const Fixed& copyop)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixedval_ = copyop.getRawBits();
	return (*this); //return the existing object
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// returns raw value of the fixed-point value
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(fixedval_);
}

// sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedval_ = raw;
}