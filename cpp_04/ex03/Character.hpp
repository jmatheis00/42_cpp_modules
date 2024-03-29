/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:21:08 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:25:30 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string name_;
    int current_;
    AMateria *inventory_[4];
    AMateria *unequipped_[100];
    int count_;

public:
    Character(); // Default Constructor
    Character(std::string name);
    Character(const Character &copyclass);         // Copy Constructor
    Character &operator=(const Character &copyop); // copy assignment operator
    virtual ~Character();                          // Destructor

    void print_inventory();

    // from ICharacter
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif