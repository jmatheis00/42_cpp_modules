/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:16 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:21:14 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type_ = "WrongCat";
    std::cout << "Default Constructor WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copyclass) : WrongAnimal(copyclass)
{
    std::cout << "Copy Constructor WrongCat" << std::endl;
    type_ = copyclass.type_;
}

WrongCat &WrongCat::operator=(const WrongCat &copyop)
{
    if (this != &copyop)
        type_ = copyop.type_;
    std::cout << "Copy Assignment Operator WrongCat" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << RED "Destructor WrongCat" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void WrongCat::makeSound() const
{
    std::cout << getType() << ":\t***WrongCat MEOWWW***" << std::endl;
}
