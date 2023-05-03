/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:16 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/03 11:56:17 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type_ = "Dog";
    std::cout << "Default Constructor Dog" << std::endl;
}

Dog::Dog(const Dog &copyclass) : Animal(copyclass)
{
    std::cout << "Copy Constructor Dog" << std::endl;
    Dog::operator= (copyclass);
}

Dog& Dog::operator= (const Dog& copyop)
{
    type_ = copyop.type_;
    std::cout << "Copy Assignment Operator Dog" << std::endl;
    return(*this);
}

Dog::~Dog()
{
    std::cout << RED "Destructor Dog" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void Dog::makeSound() const
{
    std::cout << getType() << ":\tWOOOOOOOFFFFF" << std::endl;
}
