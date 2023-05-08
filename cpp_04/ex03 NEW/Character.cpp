/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:58:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/08 19:11:59 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("Default"), current_(0), count_(0)
{
    for(int i = 0; i < 4; i++)
    {
        inventory_[i] = nullptr;
        unequipped_[i] = NULL;
    }
    std::cout << "Default Constructor Character" << std::endl;
}

Character::Character(std::string name) : name_(name) , current_(0), count_(0)
{
    for(int i = 0; i < 4; i++)
    {
        inventory_[i] = nullptr;
        unequipped_[i] = NULL;
    }
    std::cout << "Constructor Character with name " << name_ << std::endl;
}

Character::Character(const Character &copyclass)
{
    name_ = copyclass.name_;
    current_ = copyclass.current_;
    count_ = copyclass.count_;
    for(int i = 0; i < 4; i ++)
    {
        if (copyclass.inventory_[i])
            inventory_[i] = copyclass.inventory_[i]->clone();
        if (copyclass.unequipped_[i])
            unequipped_[i] = copyclass.unequipped_[i]->clone();
    }
    std::cout << "Copy Constructor Character" << std::endl;
}

Character& Character::operator= (const Character& copyop)
{
    name_ = copyop.name_;
    current_ = copyop.current_;
    count_ = copyop.count_;
    for(int i = 0; i < 4; i++)
    {
        if (inventory_[i])
            delete inventory_[i];
        if (unequipped_[i])
            delete unequipped_[i];
    }
    for(int i = 0; i < 4; i++)
    {
        if (copyop.inventory_[i])
            inventory_[i] = copyop.inventory_[i]->clone();
        if (copyop.unequipped_[i])
            unequipped_[i] = copyop.unequipped_[i]->clone();
    }
    std::cout << "Copy Assignment Operator Character" << std::endl;
    return(*this);
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
    {
        delete inventory_[i];
        delete unequipped_[i];
    }
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
            std::cout << nullptr << std::endl;
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
    while (current_ < 4 && inventory_[current_])
        current_++;
    if (current_ < 4)
    {
        inventory_[current_] = m;
        std::cout << BLUE "Equipped position: " << current_ << RESET << std::endl;
    }
    else
    {
        std::cout << BLUE "Inventory is full, cannot equip Materia" RESET << std::endl;
    }
    current_ = 0;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        unequipped_[count_] = inventory_[idx];
        inventory_[idx] = nullptr;
        std::cout << BLUE "Unequipped position: " << idx << RESET << std::endl;
        count_++;
    }
    else
        std::cout << BLUE "Unequipped position out of range"<< RESET << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory_[idx])
        inventory_[idx]->use(target);
}