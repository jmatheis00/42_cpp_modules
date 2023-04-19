/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:16 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 09:55:29 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type_ = "Cat";
    std::cout << "Default Constructor Cat"  RESET << std::endl;
}

Cat::Cat(const Cat &copyclass) : Animal(copyclass)
{
    Cat::operator= (copyclass);
}

Cat& Cat::operator= (const Cat& copyop)
{
    type_ = copyop.type_;

    return(*this);
}

Cat::~Cat()
{
    std::cout << RED "Destructor Cat" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void Cat::makeSound() const
{
    std::cout << getType() << "***Cat Sound***" << std::endl;
}
