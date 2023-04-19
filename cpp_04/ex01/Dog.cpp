/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:16 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 14:59:10 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal()
{
    type_ = "Dog";
    brain_ = new Brain();
    std::cout << "Default Constructor Dog" << std::endl;
}

Dog::Dog(const Dog &copyclass) : Animal(copyclass)
{
    Dog::operator= (copyclass);
    std::cout << "Copy Constructor Dog" << std::endl;
}

Dog& Dog::operator= (const Dog& copyop)
{
    type_ = copyop.type_;
    if (brain_)
        delete brain_;
    brain_ = new Brain(*copyop.brain_);
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

// Brain ideas
std::string Dog::getidea(int i)
{
    return(brain_->get_idea(i));
}

void Dog::setidea(int i, std::string content)
{
    brain_->set_idea(i, content);
}