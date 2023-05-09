/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:28 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/09 13:14:43 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* brain_;
    public:
        Cat(); //Default Constructor
        Cat(const Cat &copyclass); //Copy Constructor
        Cat& operator= (const Cat& copyop); //copy assignment operator
        virtual ~Cat(); //Destructor

        void makeSound() const;

        // Brain
        std::string getidea(int i);
        void setidea(int i, std::string content);
};

#endif