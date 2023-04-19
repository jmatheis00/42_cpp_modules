/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:28 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 09:32:53 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(); //Default Constructor
        Dog(const Dog &copyclass); //Copy Constructor
        Dog& operator= (const Dog& copyop); //copy assignment operator
        ~Dog(); //Destructor

        void makeSound() const;
};

#endif