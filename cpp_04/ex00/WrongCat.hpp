/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:28 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 09:58:50 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Animal.hpp"

class WrongCat : public Animal
{
    public:
        WrongCat(); //Default Constructor
        WrongCat(const WrongCat &copyclass); //Copy Constructor
        WrongCat& operator= (const WrongCat& copyop); //copy assignment operator
        ~WrongCat(); //Destructor

        void makeSound() const;
};

#endif