/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:25:58 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/22 12:31:11 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"


// OTHER MEMBER FUNCTIONS

// copies Materia Passed as a parameter
// stores it in memory so it can be cloned later
// Like the Character, MateriaSource can know
// at most 4 Materias
// they are not necessarily unique
void learnMateria(AMateria*)
{
    
}

// returns a new Materia
// the latter is a copy of the Materia previously
// learned by the MateriaSource whose type equals
// the one passed as a parameter
// returns 0 if type is unknown
AMateria* createMateria(std::string const& type)
{

}