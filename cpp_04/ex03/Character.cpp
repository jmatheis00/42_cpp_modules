/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:58:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/25 17:29:09 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("Default"), current_(0)
{
    for(int i = 0; i < 4; i++)
        inventory_[i] = NULL;
    std::cout << "Default Constructor Character" << std::endl;
}

Character::Character(std::string name) : name_(name)
{
    std::cout << "Constructor Character with name " << name_ << std::endl;
}

Character::Character(const Character &copyclass)
{
    Character::operator= (copyclass);
    std::cout << "Copy Constructor Character" << std::endl;
}

Character& Character::operator= (const Character& copyop)
{
    name_ = copyop.name_;
    current_ = copyop.current_;
    for(int i = 0; i < 4; i ++)
        inventory_[i] = copyop.inventory_[i];
    std::cout << "Copy Assignment Operator Character" << std::endl;
    return(*this);
}

Character::~Character()
{
    std::cout << RED "Destructor Character" RESET << std::endl;
}

// INTERFACE MEMBER FUNCTIONS

std::string const & Character::getName() const
{
    return (name_);
}

void Character::equip(AMateria *m)
{
    if (current_ < 4)
        inventory_[current_] = m;
    current_++;
    std::cout << "this is equip function" << std::endl;
}

void Character::unequip(int idx)
{
    inventory_[idx] = NULL;
    std::cout << "Unequip index: " << idx;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 4 && inventory_[idx] != NULL)
        inventory_[idx]->use(target);
}