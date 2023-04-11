/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:07:44 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/11 16:56:18 by jmatheis         ###   ########.fr       */
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
		Fixed(int const i);
		Fixed(float const i);
		Fixed(const Fixed &copyclass); //Copy Constructor
		Fixed& operator= (const Fixed& copyop); //copy assignment operator
		~Fixed(); //Destructor
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& i);

#endif