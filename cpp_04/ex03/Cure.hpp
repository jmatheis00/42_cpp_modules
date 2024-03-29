/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:21:08 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:25:41 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
private:
    std::string type_;

public:
    Cure();                              // Default Constructor
    Cure(const Cure &copyclass);         // Copy Constructor
    Cure &operator=(const Cure &copyop); // copy assignment operator
    virtual ~Cure();                     // Destructor

    // from AMateria
    AMateria *clone() const;
    void use(ICharacter &target);
    std::string const &getType() const;
};

#endif