/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:58:52 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/22 20:51:32 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default Constructor MateriaSource" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copyclass)
{
    MateriaSource::operator= (copyclass);
    std::cout << "Copy Constructor MateriaSource" << std::endl;
}

MateriaSource& MateriaSource::operator= (const MateriaSource& copyop)
{
    copyop = (MateriaSource&)copyop;
    // type_ = copyop.type_;
    std::cout << "Copy Assignment Operator MateriaSource" << std::endl;
    return(*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << RED "Destructor MateriaSource" RESET << std::endl;
}

// Interface functions 

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    if (type == "ice")
        AMateria* newest= new Ice;
    else if (type == "cure")
        AMateria* newest= new Cure;
    else
        std::cout << "undefined type" << std::endl;
    return(newest);
}