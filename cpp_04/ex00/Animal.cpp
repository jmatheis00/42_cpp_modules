/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:28:01 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 09:46:16 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    type_ = "Animal";
    std::cout << "Default Constructor Animal"  RESET << std::endl;
}

Animal::Animal(const Animal &copyclass)
{
    Animal::operator= (copyclass);
}

Animal& Animal::operator= (const Animal& copyop)
{
    type_ = copyop.type_;

    return(*this);
}

Animal::~Animal()
{
    std::cout << RED "Destructor Animal" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void Animal::makeSound() const
{
    std::cout << this->getType() << "***Animal Sound***" << std::endl;
}

std::string Animal::getType() const
{
    return(type_);
}
