/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:21:08 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/22 12:18:02 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

// inherits from ICharacter?
// CANONICAL FORM!
class Cure : public AMateria
{
    private:
        std::string type_;
    public:
        Cure(); //Default Constructor
		Cure(const Cure &copyclass); //Copy Constructor
		Cure& operator= (const Cure& copyop); //copy assignment operator
		virtual ~Cure(); //Destructor  

        Cure* clone() const;     

};

#endif