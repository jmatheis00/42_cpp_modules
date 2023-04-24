/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:11:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/24 09:54:13 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::fractbits_ = 8;

// ORTHODOX CANONICAL
Fixed::Fixed() : fixedval_(0)
{

}

Fixed::Fixed(const Fixed& copyclass)
{
	Fixed::operator= (copyclass);
}

Fixed& Fixed::operator= (const Fixed& copyop)
{
	fixedval_ = copyop.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{

}

// OTHER MEMBER FUNCTIONS
Fixed::Fixed(int const i)
{
	fixedval_ = i * (1 << fractbits_);
}

Fixed::Fixed(float const i)
{
	fixedval_ = roundf(i * (1 << fractbits_));
}

int Fixed::getRawBits(void) const
{
	return(fixedval_);
}

void Fixed::setRawBits(int const raw)
{
	fixedval_ = raw;
}

float Fixed::toFloat(void) const
{
	float temp;

	temp = (float(fixedval_) / (1 << fractbits_));
	return (temp);
}

int Fixed::toInt(void) const
{
	int tmp;

	tmp = fixedval_ / (1 << fractbits_);
	return(tmp);
}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const Fixed& i)
{
	os << i.toFloat();
	return (os);
}

// COMPARISON OPERATOR OVERLOADING
bool Fixed::operator==(const Fixed& a) const
{
	return(this->getRawBits() == a.getRawBits());
}

bool Fixed::operator!=(const Fixed& a) const
{
	return(this->getRawBits() != a.getRawBits());
}

bool Fixed::operator<=(const Fixed& a) const
{
	return(this->getRawBits() <= a.getRawBits());
}

bool Fixed::operator>=(const Fixed& a) const
{
	return(this->getRawBits() >= a.getRawBits());
}

bool Fixed::operator<(const Fixed& a) const
{
	return(this->getRawBits() < a.getRawBits());
}

bool Fixed::operator>(const Fixed& a) const
{
	return(this->getRawBits() > a.getRawBits());
}

// ARITHMETIC OPERATOR OVERLOADING
Fixed Fixed::operator+(const Fixed& a) const
{
	return(this->toFloat() + a.toFloat());
}

Fixed Fixed::operator-(const Fixed& a) const
{
	return(this->toFloat() - a.toFloat());
}

Fixed Fixed::operator*(const Fixed& a) const
{
	return(this->toFloat() * a.toFloat());
}

Fixed Fixed::operator/(const Fixed& a) const
{
	return(this->toFloat() / a.toFloat());
}

// PRE X-CREMENT OPERATOR OVERLOADING
Fixed& Fixed::operator++()
{
	++(this->fixedval_);
	return(*this);
}

Fixed& Fixed::operator--()
{
	--(this->fixedval_);
	return(*this);
}

// POST X-CREMENT OPERATOR OVERLOADING
// fictive argument to seperate between pre and post
Fixed Fixed::operator++(int i)
{
	Fixed a = *this;
	i = (int)i;
	(this->fixedval_)++;
	return(a);
}

Fixed Fixed::operator--(int i)
{
	Fixed a = *this;
	i = (int)i;
	(this->fixedval_)--;
	return(a);
}

// OVERLOADED MEMBER FUNCTIONS
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return(b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return(b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return(b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return(b);
}
