/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:58:52 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/07 23:05:28 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : current_(0)
{
    for(int i = 0; i < 4; i++)
        inventory_[i] = NULL;
    std::cout << "Default Constructor MateriaSource" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copyclass)
{
    for(int i = 0; i < 4; i ++)
        inventory_[i] = copyclass.inventory_[i]->clone(); //deep copy?
    std::cout << "Copy Constructor MateriaSource" << std::endl;
}

MateriaSource& MateriaSource::operator= (const MateriaSource& copyop)
{
    current_ = copyop.current_;
    for(int i = 0; i < 4; i ++)
        delete inventory_[i]; //deep copy?
    for(int i = 0; i < 4; i ++)
        inventory_[i] = copyop.inventory_[i]->clone(); //deep copy?
    std::cout << "Copy Assignment Operator MateriaSource" << std::endl;
    return(*this);
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i ++)
        delete inventory_[i];
    std::cout << RED "Destructor MateriaSource" RESET << std::endl;
}

// Interface functions 

// gets added to "inventory/storage"
void MateriaSource::learnMateria(AMateria* m)
{
    if (current_ < 4)
        inventory_[current_] = m;
    current_++;
}

// create new materia with right type
AMateria* MateriaSource::createMateria(std::string const& type)
{
    if (type == "ice")
        return (new Ice);
    else if (type == "cure")
        return (new Cure);
    return (0);
}