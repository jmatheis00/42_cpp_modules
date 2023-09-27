/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:58:52 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:26:31 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : current_(0)
{
    for (int i = 0; i < 4; i++)
        sourceinventory_[i] = NULL;
    std::cout << "Default Constructor MateriaSource" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copyclass) : IMateriaSource(copyclass)
{
    for (int i = 0; i < 4; i++)
        sourceinventory_[i] = copyclass.sourceinventory_[i]->clone();
    std::cout << "Copy Constructor MateriaSource" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copyop)
{
    current_ = copyop.current_;
    for (int i = 0; i < 4; i++)
    {
        if (sourceinventory_[i])
            delete sourceinventory_[i];
    }
    for (int i = 0; i < 4; i++)
        sourceinventory_[i] = copyop.sourceinventory_[i]->clone();
    std::cout << "Copy Assignment Operator MateriaSource" << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (sourceinventory_[i])
            delete sourceinventory_[i];
    }
    std::cout << RED "Destructor MateriaSource" RESET << std::endl;
}

// Interface functions

// gets created --> exist to put to inventory of character
void MateriaSource::learnMateria(AMateria *m)
{
    if (m == NULL)
    {
        std::cout << BLUE "cannot learn Materia type that doesn't exist" RESET << std::endl;
        return;
    }
    if (current_ < 4)
    {
        sourceinventory_[current_] = m;
        std::cout << BLUE "learned Materia: " << m->getType() << RESET << std::endl;
        current_++;
    }
    else
        std::cout << BLUE "full storage, cannot learn new Materia!" << RESET << std::endl;
}

// create new materia with right type
AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < current_; i++)
    {
        if (type == sourceinventory_[i]->getType())
        {
            std::cout << BLUE "create Materia: " << sourceinventory_[i]->getType() << RESET << std::endl;
            return (sourceinventory_[i]->clone());
        }
    }
    std::cout << BLUE "cannot create Materia that is unkown/not learned!" << RESET << std::endl;
    return (0);
}