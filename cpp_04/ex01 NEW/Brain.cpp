/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:56:40 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/03 12:32:24 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Constructor Brain" << std::endl;
}

Brain::Brain(const Brain &copyclass)
{
    std::cout << "Copy Constructor Brain" << std::endl;
    Brain::operator= (copyclass);
}

Brain& Brain::operator= (const Brain& copyop)
{
    for(int i = 0; i < 100; i++)
        ideas_[i] = copyop.ideas_[i];
    std::cout << "Copy Assignment Operator Brain" << std::endl;
    return(*this);
}

Brain::~Brain()
{
    std::cout << RED "Destructor Brain" RESET << std::endl;
}

// other member functions
std::string Brain::get_idea(int i)
{
    return(ideas_[i]);
}

void Brain::set_idea(int i, std::string content)
{
    ideas_[i] = content;
}