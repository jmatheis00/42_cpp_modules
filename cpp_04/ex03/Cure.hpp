/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:21:08 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/21 13:01:42 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

// inherits from ICharacter?
// CANONICAL FORM!
class Cure : public AMateria
{
    private:

    public:
        Cure(); //Default Constructor
		Cure(const Cure &copyclass); //Copy Constructor
		Cure& operator= (const Cure& copyop); //copy assignment operator
		virtual ~Cure(); //Destructor       

};

#endif