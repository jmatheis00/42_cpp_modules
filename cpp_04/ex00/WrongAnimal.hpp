/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:27:27 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 11:09:19 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */

class WrongAnimal
{
    protected:
        std::string type_;
    public:
        WrongAnimal(); //Default Constructor
		WrongAnimal(const WrongAnimal &copyclass); //Copy Constructor
		WrongAnimal& operator= (const WrongAnimal& copyop); //copy assignment operator
		~WrongAnimal(); //Destructor

        void makeSound() const;
        std::string getType() const;
};

#endif