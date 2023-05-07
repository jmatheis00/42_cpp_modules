/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:21:08 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/25 16:44:43 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

// inherits from ICharacter?
// CANONICAL FORM!
class Character : public ICharacter
{
    private:
        std::string name_;
        int current_;
        AMateria* inventory_[4];
        Character(); //Default Constructor
    public:
        Character(std::string name);
		Character(const Character &copyclass); //Copy Constructor
		Character& operator= (const Character& copyop); //copy assignment operator
		virtual ~Character(); //Destructor

        // from ICharacter
        std::string const & getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

};

#endif