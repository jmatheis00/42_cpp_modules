/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:28:01 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 09:59:10 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type_ = "WrongAnimal";
    std::cout << "Default Constructor WrongAnimal"  RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copyclass)
{
    WrongAnimal::operator= (copyclass);
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& copyop)
{
    type_ = copyop.type_;

    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << RED "Destructor WrongAnimal" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void WrongAnimal::makeSound() const
{
    std::cout << this->getType() << "***WrongAnimal Sound***" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(type_);
}
