/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:27:27 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/17 19:30:08 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */

class Animal
{
    protected:
        std::string type;
    public:
        Animal(); //Default Constructor
		// Animal(std::string name); 
		Animal(const Animal &copyclass); //Copy Constructor
		Animal& operator= (const Animal& copyop); //copy assignment operator
		~Animal(); //Destructor
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& os, const Animal& i);

#endif