/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:57:58 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/22 12:15:25 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    type_ = "AMateria DEFAULT";
    std::cout << "Default Constructor AMateria" << std::endl;
}

AMateria::AMateria(std::string const& type)
{
    type_ = type;
    std::cout << "Constructor AMateria" << std::endl;
}

AMateria::AMateria(const AMateria &copyclass)
{
    AMateria::operator= (copyclass);
    std::cout << "Copy Constructor AMateria" << std::endl;
}

AMateria& AMateria::operator= (const AMateria& copyop)
{
    type_ = copyop.type_;
    std::cout << "Copy Assignment Operator AMateria" << std::endl;
    return(*this);
}

AMateria::~AMateria()
{
    std::cout << RED "Destructor AMateria" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS

//returns the materia type
std::string const& AMateria::getType() const
{
    return (type_);
}

AMateria* AMateria::clone() const
{

}

// name is the name of the Character passed as parameter
void AMateria::use(ICharacter& target)
{
    // if (target == "Ice")
        std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
    // else if (target == "Cube")
        std::cout << "* heals " << target << "\'s wounds *" << std::endl;
}