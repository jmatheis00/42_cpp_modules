/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:21:08 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/22 20:50:29 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MateriaSource_HPP
#define MateriaSource_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class Ice;
class Cure;

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource(); //Default Constructor
		MateriaSource(const MateriaSource &copyclass); //Copy Constructor
		MateriaSource& operator= (const MateriaSource& copyop); //copy assignment operator
		virtual ~MateriaSource(); //Destructor

        // From IMateriaSource
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const& type);
};

#endif