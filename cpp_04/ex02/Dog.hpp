/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:28 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/21 11:38:33 by jmatheis         ###   ########.fr       */
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
        virtual Dog& operator= (const Dog& copyop); //copy assignment operator
        ~Dog(); //Destructor

        void makeSound() const;
        // Brain ideas
        std::string getidea(int i);
        void setidea(int i, std::string content);
};

#endif