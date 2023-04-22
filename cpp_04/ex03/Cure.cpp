/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:58:22 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/22 12:18:38 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    type_ = "cure";
    std::cout << "Default Constructor Cure" << std::endl;
}

Cure::Cure(const Cure &copyclass)
{
    Cure::operator= (copyclass);
    std::cout << "Copy Constructor Cure" << std::endl;
}

Cure& Cure::operator= (const Cure& copyop)
{
    type_ = copyop.type_;
    std::cout << "Copy Assignment Operator Cure" << std::endl;
    return(*this);
}

Cure::~Cure()
{
    std::cout << RED "Destructor Cure" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS

// Return a new instance of the same type
Cure* Cure::clone() const
{
    
}