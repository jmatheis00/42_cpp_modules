/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:58:31 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:25:48 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    type_ = "ice";
    std::cout << "Default Constructor Ice" << std::endl;
}

Ice::Ice(const Ice &copyclass) : AMateria(copyclass)
{
    type_ = copyclass.type_;
    std::cout << "Copy Constructor Ice" << std::endl;
}

Ice &Ice::operator=(const Ice &copyop)
{
    if (this != &copyop)
        type_ = copyop.type_;
    std::cout << "Copy Assignment Operator Ice" << std::endl;
    return (*this);
}

Ice::~Ice()
{
    std::cout << RED "Destructor Ice" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS

std::string const &Ice::getType() const
{
    return (type_);
}

// Return a new instance of the same type
AMateria *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at "
              << target.getName() << " *" << std::endl;
}