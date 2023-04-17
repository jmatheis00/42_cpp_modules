/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:28:01 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/17 19:33:26 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default Constructor Animal"  RESET << std::endl;
}

Animal::Animal(const Animal &copyclass)
{
    Animal::operator= (copyclass);
}

Animal& Animal::operator= (const Animal& copyop)
{
    type_ = copyop.type_();

    return(*this);
}

Animal::~Animal()
{
    std::cout << RED "Destructor Animal" RESET << std::endl;
}


// GETTER FUNCTIONS


// OTHER MEMBER FUNCTIONS

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const Animal& i)
{
	// os << "TYPE\t\t" << i.get_name() << std::endl;
	return (os);
}
