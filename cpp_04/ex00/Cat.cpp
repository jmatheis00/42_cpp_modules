/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:16 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/05 13:46:30 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type_ = "Cat";
    std::cout << "Default Constructor Cat" << std::endl;
}

Cat::Cat(const Cat &copyclass) : Animal(copyclass)
{
    std::cout << "Copy Constructor Cat" << std::endl;
    type_ = copyclass.type_;
}

Cat& Cat::operator= (const Cat& copyop)
{
    if (this != &copyop)
        type_ = copyop.type_;
    std::cout << "Copy Assignment Operator Cat" << std::endl;
    return(*this);
}

Cat::~Cat()
{
    std::cout << RED "Destructor Cat" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void Cat::makeSound() const
{
    std::cout << getType() << ":\tMEOOOOOWWWWW" << std::endl;
}
