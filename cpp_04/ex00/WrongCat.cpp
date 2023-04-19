/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:16 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 09:58:30 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : Animal()
{
    type_ = "WrongCat";
    std::cout << "Default Constructor WrongCat"  RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &copyclass) : Animal(copyclass)
{
    WrongCat::operator= (copyclass);
}

WrongCat& WrongCat::operator= (const WrongCat& copyop)
{
    type_ = copyop.type_;

    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << RED "Destructor WrongCat" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void WrongCat::makeSound() const
{
    std::cout << getType() << "***WrongCat Sound***" << std::endl;
}
