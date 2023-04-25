/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:21:08 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/25 16:58:33 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

// inherits from ICharacter?
// CANONICAL FORM!
class Ice : public AMateria
{
    private:
        std::string type_;
    public:
        Ice(); //Default Constructor
		Ice(const Ice &copyclass); //Copy Constructor
		Ice& operator= (const Ice& copyop); //copy assignment operator
		virtual ~Ice(); //Destructor       

        AMateria* clone() const;
        void use(ICharacter& target);

};

#endif