/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:21:08 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:26:37 by jmatheis         ###   ########.fr       */
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
    AMateria *sourceinventory_[4];
    int current_;

public:
    MateriaSource();                                       // Default Constructor
    MateriaSource(const MateriaSource &copyclass);         // Copy Constructor
    MateriaSource &operator=(const MateriaSource &copyop); // copy assignment operator
    virtual ~MateriaSource();                              // Destructor

    // From IMateriaSource
    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);
};

#endif