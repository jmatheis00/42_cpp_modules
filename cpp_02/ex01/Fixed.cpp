/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:11:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/21 16:55:38 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::fractbits_ = 8;

Fixed::Fixed() : fixedval_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// takes a constant integer as a parameter
// converts it to the corresponding fixed-point value
// fractional bits value initialized to 8
Fixed::Fixed(int const i)
{
	std::cout << "Int constructor called" << std::endl;
	fixedval_ = i;
	std::cout << "fixedval_ int " << fixedval_ << std::endl;
}

// takes a constant float as a parameter
// converts it to the corresponding fixed-point value
// fractional bits value initialized to 8
Fixed::Fixed(float const i)
{
	std::cout << "Float constructor called" << std::endl;
	fixedval_ = i;
}

Fixed::Fixed(const Fixed& copyclass)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedval_ = copyclass.getRawBits();
}

Fixed& Fixed::operator= (const Fixed& copyop)
{
	std::cout << "copy assignment operator called" << std::endl;
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

//converts fixed point value to a floating point value
float Fixed::toFloat(void) const
{
	float temp = 0.0;

	// std::cout << "fixedval " << fixedval_ << std::endl;
	temp = fixedval_;
	return (temp);
}

// roundf(num): returns nearest integer value to num
// converts fixed point value to an integer value
int Fixed::toInt(void) const
{
	int tmp;

	tmp = fixedval_;
	return(tmp);
}

std::ostream& operator<<(std::ostream& os, const Fixed& i)
{
	os << i.toFloat();
	return (os);
}