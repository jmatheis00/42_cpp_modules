/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:11:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/13 15:50:22 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedval_(0)
{
	// fixedval_ = 0;
	std::cout << "Default Constructor" << std::endl;
}

Fixed::Fixed(const Fixed &copyclass)
{
	fixedval_ = copyclass.fixedval_;
	std::cout << "Copy Constructor" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& copyop)
{
	fixedval_ = copyop.fixedval_;
	// fractbits_ = copyop.fractbits_;
	std::cout << "copy assignment constructor" << std::endl;
	return (*this); //return the existing object
}

Fixed::~Fixed()
{
	std::cout << "Destructor" << std::endl;
}

// returns raw value of the fixed-point value
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits" << std::endl;
	return(fixedval_);
}

// sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits" << std::endl;
	std::cout << raw << std::endl;
}