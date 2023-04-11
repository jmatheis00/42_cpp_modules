/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:07:44 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/11 20:30:05 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#include <ostream>

#define RESET       "\033[0m"
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */

class Fixed
{
	private:
		int	fixedval_;
		static const int fractbits_;
	public:
		Fixed(); //Default Constructor
		Fixed(const Fixed &copyclass); //Copy Constructor
		Fixed& operator= (const Fixed& copyop); //copy assignment operator
		~Fixed(); //Destructor

		Fixed(int const i);
		Fixed(float const i);

		// COMPARISON OPERATOR OVERLOADING
		bool operator==(const Fixed& a) const;
		bool operator!=(const Fixed& a) const;
		bool operator<=(const Fixed& a) const;
		bool operator>=(const Fixed& a) const;
		bool operator<(const Fixed& a) const;
		bool operator>(const Fixed& a) const;

		// ARITHMETIC OPERATOR OVERLOADING
		Fixed operator+(const Fixed& a) const;
		Fixed operator-(const Fixed& a) const;
		Fixed operator*(const Fixed& a) const;
		Fixed operator/(const Fixed& a) const;
		
		// PRAE X-CREMENT OPERATOR OVERLOADING
		Fixed& operator++();
		Fixed& operator--();
		// POST X-CREMENT OPERATOR OVERLOADING
		// fictive argument to seperate between prae and post
		Fixed operator++(int i);
		Fixed operator--(int i);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		
		// OVERLOADED MEMBER FUNCTIONS
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);		

};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& os, const Fixed& i);

#endif