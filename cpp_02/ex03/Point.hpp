/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:00:49 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/23 22:12:58 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <cmath>
#include <ostream>
#include "Fixed.hpp"

#define RESET       "\033[0m"
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */

class Point
{
	private:
		const Fixed x_;
		const Fixed y_;
	public:
		Point(); //Default Constructor
		Point(const Point &copyclass); //Copy Constructor
		Point& operator= (const Point& copyop); //copy assignment operator
		~Point(); //Destructor
        Fixed getX() const;
        Fixed getY() const;
        Point(const float a, const float b);
};

#endif