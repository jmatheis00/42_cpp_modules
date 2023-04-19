/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:16 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 11:17:14 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type_ = "WrongCat";
    std::cout << "Default Constructor WrongCat"  RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &copyclass) : WrongAnimal(copyclass)
{
    WrongCat::operator= (copyclass);
    std::cout << "Copy Constructor WrongCat"  RESET << std::endl;
}

WrongCat& WrongCat::operator= (const WrongCat& copyop)
{
    type_ = copyop.type_;
    std::cout << "Copy Assignment Operator WrongCat"  RESET << std::endl;
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << RED "Destructor WrongCat" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void WrongCat::makeSound() const
{
    std::cout << getType() << ":\t***WrongCat Sound***" << std::endl;
}
