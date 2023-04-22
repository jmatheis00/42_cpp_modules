/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:58:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/22 20:46:47 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    name_ = "DEFAULT";
    std::cout << "Default Constructor Character" << std::endl;
}

Character::Character(std::string name)
{
    name_ = name;
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
    std::cout << "This is the name of character: " << name_;
    return (name_);
}

void Character::equip(AMateria *m)
{
    m = (AMateria *)m;
    std::cout << "this is equip function" << std::endl;
}

void Character::unequip(int idx)
{
    std::cout << "Unequip index: " << idx;
    idx += 1;
}

void Character::use(int idx, ICharacter& target)
{
    target = (ICharacter&)target;
    std::cout << "THis is use function with idx: " << idx;
    if (idx < 0)
        idx += 1;
}