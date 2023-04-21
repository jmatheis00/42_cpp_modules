/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:21:08 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/21 12:56:55 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

// inherits from ICharacter?
// CANONICAL FORM!
class Character
{
    private:
        std::string name_;
    public:
        Character(); //Default Constructor
        Character(std::string name);
		Character(const Character &copyclass); //Copy Constructor
		Character& operator= (const Character& copyop); //copy assignment operator
		virtual ~Character(); //Destructor       

};

#endif