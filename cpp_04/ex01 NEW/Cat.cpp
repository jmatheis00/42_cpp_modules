/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:16 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/03 12:52:22 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type_ = "Cat";
    brain_ = new Brain;
    std::cout << "Default Constructor Cat" << std::endl;
}

Cat::Cat(const Cat &copyclass) : Animal(copyclass)
{
    std::cout << "Copy Constructor Cat" << std::endl;
    Cat::operator= (copyclass);
}

Cat& Cat::operator= (const Cat& copyop)
{
    if (this != &copyop)
    {
        brain_ = new Brain(*copyop.brain_);
        type_ = copyop.type_;
    }
    std::cout << "Copy Assignment Operator Cat" << std::endl;
    return(*this);
}

Cat::~Cat()
{
    delete brain_;
    std::cout << RED "Destructor Cat" RESET << std::endl;
}

// OTHER MEMBER FUNCTIONS
void Cat::makeSound() const
{
    std::cout << getType() << ":\tMEOOOOOWWWWW" << std::endl;
}

// Brain
std::string Cat::getidea(int i)
{
    return(brain_->get_idea(i));
}

void Cat::setidea(int i, std::string content)
{
    brain_->set_idea(i, content);
}