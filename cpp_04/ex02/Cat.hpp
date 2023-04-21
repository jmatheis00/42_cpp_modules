/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:11:28 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 14:16:51 by jmatheis         ###   ########.fr       */
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
        ~Cat(); //Destructor

        void makeSound() const;
        // Brain ideas
        std::string getidea(int i);
        void setidea(int i, std::string content);
};

#endif