/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:16 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/03 12:52:18 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type_ = "Dog";
    brain_ = new Brain;
    std::cout << "Default Constructor Dog" << std::endl;
}

Dog::Dog(const Dog &copyclass) : Animal(copyclass)
{
    std::cout << "Copy Constructor Dog" << std::endl;
    Dog::operator= (copyclass);
}

Dog& Dog::operator= (const Dog& copyop)
{
    if (this != &copyop)
    {
        brain_ = new Brain(*copyop.brain_);
        type_ = copyop.type_;
    }
    std::cout << "Copy Assignment Operator Dog" << std::endl;
    return(*this);
}

Dog::~Dog()
{
    delete brain_;
    std::cout << RED "Destructor Dog" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void Dog::makeSound() const
{
    std::cout << getType() << ":\tWOOOOOOOFFFFF" << std::endl;
}

// Brain
std::string Dog::getidea(int i)
{
    return(brain_->get_idea(i));
}

void Dog::setidea(int i, std::string content)
{
    brain_->set_idea(i, content);
}