/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:58:22 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:25:34 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    type_ = "cure";
    std::cout << "Default Constructor Cure" << std::endl;
}

Cure::Cure(const Cure &copyclass) : AMateria(copyclass)
{
    type_ = copyclass.type_;
    std::cout << "Copy Constructor Cure" << std::endl;
}

Cure &Cure::operator=(const Cure &copyop)
{
    if (this != &copyop)
        type_ = copyop.type_;
    std::cout << "Copy Assignment Operator Cure" << std::endl;
    return (*this);
}

Cure::~Cure()
{
    std::cout << RED "Destructor Cure" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS

std::string const &Cure::getType() const
{
    return (type_);
}

// Return a new instance of the same type
AMateria *Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName()
              << "\'s wounds *" << std::endl;
}