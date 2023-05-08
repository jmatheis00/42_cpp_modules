/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:58:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/08 13:50:12 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("Default"), current_(0)
{
    for(int i = 0; i < 4; i++)
        inventory_[i] = NULL;
    std::cout << "Default Constructor Character" << std::endl;
}

Character::Character(std::string name) : name_(name) , current_(0)
{
    for(int i = 0; i < 4; i++)
        inventory_[i] = NULL;
    std::cout << "Constructor Character with name " << name_ << std::endl;
}

Character::Character(const Character &copyclass)
{
    for(int i = 0; i < 4; i ++)
        inventory_[i] = copyclass.inventory_[i]->clone(); //deep copy?
    std::cout << "Copy Constructor Character" << std::endl;
}

Character& Character::operator= (const Character& copyop)
{
    name_ = copyop.name_;
    current_ = copyop.current_;
    for(int i = 0; i < 4; i ++)
        delete inventory_[i]; //deep copy?
    for(int i = 0; i < 4; i ++)
        inventory_[i] = copyop.inventory_[i]->clone(); //deep copy?
    std::cout << "Copy Assignment Operator Character" << std::endl;
    return(*this);
}

Character::~Character()
{
    for(int i = 0; i < 4; i ++)
        delete inventory_[i];
    std::cout << RED "Destructor Character" RESET << std::endl;
}


// Other member functions

void Character::print_inventory()
{
    int i = 0;

    while(i < 4)
    {
        std::cout << "pos: " << i << "\t";
        if (inventory_[i])
            std::cout << inventory_[i]->getType() << std::endl;
        else
            std::cout << "NULL" << std::endl;
        i++;
    }
}


// INTERFACE MEMBER FUNCTIONS

std::string const & Character::getName() const
{
    return (name_);
}

void Character::equip(AMateria *m)
{
    if (m == 0)
    {
        std::cout << BLUE "uncreated materia cannot get equipped" RESET << std::endl;
        return ;
    }
    while(current_ < 4 && inventory_[current_] != NULL)
        current_++;
    if (current_ < 4)
    {
        inventory_[current_] = m;
        std::cout << BLUE "Equipped position: " << current_ << RESET << std::endl;
    }
    else
        std::cout << BLUE "Inventory is full, cannot equip Materia" RESET << std::endl;
    current_ = 0;
}

void Character::unequip(int idx)
{
    inventory_[idx] = NULL;
    std::cout << BLUE "Unequipped position: " << idx << RESET << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 4 && inventory_[idx] != NULL)
        inventory_[idx]->use(target);
}