/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:13:20 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:25:08 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

#define RESET "\033[0m"   /* Reset */
#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define PURPLE "\033[35m" /* Purple */
#define BLUE "\033[36m"   /* Blue */

// Forward declaration necessary when we use
// reference or pointer to this class
class ICharacter;

class AMateria
{
protected:
    std::string type_;
    AMateria(); // Default Constructor
public:
    AMateria(std::string const &type);

    // virtual -> get type of ice and cure
    virtual std::string const &getType() const; // returns the materia type

    AMateria(const AMateria &copyclass);         // Copy Constructor
    AMateria &operator=(const AMateria &copyop); // copy assignment operator
    virtual ~AMateria();                         // Destructor

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif