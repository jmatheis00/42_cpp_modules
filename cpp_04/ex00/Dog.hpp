/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:28 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:20:42 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();                             // Default Constructor
    Dog(const Dog &copyclass);         // Copy Constructor
    Dog &operator=(const Dog &copyop); // copy assignment operator
    virtual ~Dog();                    // Destructor

    void makeSound() const;
};

#endif