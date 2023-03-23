/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:00:51 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/23 22:18:38 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// ORTHODOX CANONICAL
Point::Point(): x_(0), y_(0)
{

}

Point::Point(const Point& copyclass)
{
	Point::operator= (copyclass);
}

Point& Point::operator= (const Point& copyop)
{
    // must be Fixed not const Fixed
    (Fixed)x_ = copyop.getX();
    (Fixed)y_ = copyop.getY();
    return(*this);
}

Point::~Point()
{

}

// OTHER CONSTRUCTOR

Point::Point(const float a, const float b): x_(a), y_(b)
{
    
}

Fixed Point::getX() const
{
    return(x_);
}

Fixed Point::getY() const
{
    return(y_);
}