/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:28:01 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:20:18 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    type_ = "Animal";
    std::cout << "Default Constructor Animal" << std::endl;
}

Animal::Animal(const Animal &copyclass)
{
    std::cout << "Copy Constructor Animal" << std::endl;
    type_ = copyclass.type_;
}

Animal &Animal::operator=(const Animal &copyop)
{
    if (this != &copyop)
        type_ = copyop.type_;
    std::cout << "Copy Assignment Operator Animal" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << RED "Destructor Animal" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void Animal::makeSound() const
{
    std::cout << getType() << ":\t***Animal Sound***" << std::endl;
}

std::string Animal::getType() const
{
    return (type_);
}
