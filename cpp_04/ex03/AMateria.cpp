/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:58:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:25:21 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "Default Constructor AMateria" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
    type_ = type;
    std::cout << "Default Constructor AMateria" << std::endl;
}

AMateria::AMateria(const AMateria &copyclass)
{
    AMateria::operator=(copyclass);
    std::cout << "Copy Constructor AMateria" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &copyop)
{
    type_ = copyop.type_;
    std::cout << "Copy Assignment Operator AMateria" << std::endl;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << RED "Destructor AMateria" RESET << std::endl;
}

// other member functions

std::string const &AMateria::getType() const
{
    return (type_);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}