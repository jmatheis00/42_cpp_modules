/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:21:08 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/25 17:13:28 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MateriaSource_HPP
#define MateriaSource_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* inventory_[4];
        int current_;
    public:
        MateriaSource(); //Default Constructor
		MateriaSource(const MateriaSource &copyclass); //Copy Constructor
		MateriaSource& operator= (const MateriaSource& copyop); //copy assignment operator
		virtual ~MateriaSource(); //Destructor

        // From IMateriaSource
        void learnMateria(AMateria* m); //added m here ???
        AMateria* createMateria(std::string const& type);
};

#endif