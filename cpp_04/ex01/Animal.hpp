/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:27:27 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/09 12:34:20 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

class Animal
{
    protected:
        std::string type_;
    public:
        Animal(); //Default Constructor
		Animal(const Animal &copyclass); //Copy Constructor
		Animal& operator= (const Animal& copyop); //copy assignment operator
		virtual ~Animal(); //Destructor

        virtual void makeSound() const;
        std::string getType() const;
};

#endif