/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:28:01 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 12:02:35 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type_ = "WrongAnimal";
    std::cout << "Default Constructor WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copyclass)
{
    WrongAnimal::operator= (copyclass);
    std::cout << "Copy Constructor WrongAnimal" << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& copyop)
{
    type_ = copyop.type_;
    std::cout << "Copy Assignment Operator WrongAnimal" << std::endl;
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << RED "Destructor WrongAnimal" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void WrongAnimal::makeSound() const
{
    std::cout << getType() << ":\t***WrongAnimal Sound***" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(type_);
}
