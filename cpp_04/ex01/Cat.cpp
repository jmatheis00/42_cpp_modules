/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:16 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/21 11:32:46 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
    type_ = "Cat";
    brain_ = new Brain;
    std::cout << "Default Constructor Cat" << std::endl;
}

Cat::Cat(const Cat &copyclass) : Animal(copyclass)
{
    brain_ = new Brain(*copyclass.brain_);
    type_ = copyclass.type_;
    std::cout << "Copy Constructor Cat" << std::endl;
}

Cat& Cat::operator= (const Cat& copyop)
{
    type_ = copyop.type_;
    if (brain_)
        delete brain_;
    brain_ = new Brain(*copyop.brain_);
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

// Brain ideas
std::string Cat::getidea(int i)
{
    return(brain_->get_idea(i));
}

void Cat::setidea(int i, std::string content)
{
    brain_->set_idea(i, content);
}