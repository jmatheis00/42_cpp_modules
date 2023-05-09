/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:28 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/09 13:14:46 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* brain_;
    public:
        Dog(); //Default Constructor
        Dog(const Dog &copyclass); //Copy Constructor
        Dog& operator= (const Dog& copyop); //copy assignment operator
        virtual ~Dog(); //Destructor

        void makeSound() const;

        // Brain
        std::string getidea(int i);
        void setidea(int i, std::string content);
};

#endif