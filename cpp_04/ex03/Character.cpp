/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:58:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:25:16 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("Default"), current_(0), count_(0)
{
    for (int i = 0; i < 4; i++)
        inventory_[i] = NULL;
    for (int i = 0; i < 100; i++)
        unequipped_[i] = NULL;
    std::cout << "Default Constructor Character" << std::endl;
}

Character::Character(std::string name) : name_(name), current_(0), count_(0)
{
    for (int i = 0; i < 4; i++)
        inventory_[i] = NULL;
    for (int i = 0; i < 100; i++)
        unequipped_[i] = NULL;
    std::cout << "Constructor Character with name " << name_ << std::endl;
}

Character::Character(const Character &copyclass) : ICharacter(copyclass)
{
    name_ = copyclass.name_;
    current_ = copyclass.current_;
    count_ = copyclass.count_;
    for (int i = 0; i < 4; i++)
    {
        if (copyclass.inventory_[i])
            inventory_[i] = copyclass.inventory_[i]->clone();
    }
    for (int i = 0; i < 100; i++)
    {
        if (copyclass.unequipped_[i])
            unequipped_[i] = copyclass.unequipped_[i]->clone();
    }
    std::cout << "Copy Constructor Character" << std::endl;
}

Character &Character::operator=(const Character &copyop)
{
    name_ = copyop.name_;
    current_ = copyop.current_;
    count_ = copyop.count_;
    for (int i = 0; i < 4; i++)
    {
        if (inventory_[i])
            delete inventory_[i];
        if (copyop.inventory_[i])
            inventory_[i] = copyop.inventory_[i]->clone();
    }
    for (int i = 0; i < 100; i++)
    {
        if (unequipped_[i])
            delete unequipped_[i];
        if (copyop.unequipped_[i])
            unequipped_[i] = copyop.unequipped_[i]->clone();
    }
    std::cout << "Copy Assignment Operator Character" << std::endl;
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory_[i])
            delete inventory_[i];
    }
    for (int i = 0; i < 100; i++)
    {
        if (unequipped_[i])
            delete unequipped_[i];
    }
    std::cout << RED "Destructor Character" RESET << std::endl;
}

// Other member functions

void Character::print_inventory()
{
    int i = 0;

    while (i < 4)
    {
        std::cout << "pos: " << i << "\t";
        if (inventory_[i])
            std::cout << inventory_[i]->getType() << std::endl;
        else
            std::cout << NULL << std::endl;
        i++;
    }
}

// INTERFACE MEMBER FUNCTIONS

std::string const &Character::getName() const
{
    return (name_);
}

void Character::equip(AMateria *m)
{
    if (m == 0)
    {
        std::cout << BLUE "uncreated materia cannot get equipped" RESET << std::endl;
        return;
    }
    while (current_ < 4 && inventory_[current_])
        current_++;
    if (current_ < 4)
    {
        std::cout << BLUE "Equipped position: " << current_ << RESET << std::endl;
        inventory_[current_] = m;
    }
    else
        std::cout << BLUE "Inventory is full, cannot equip Materia" RESET << std::endl;
    current_ = 0;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        unequipped_[count_] = inventory_[idx];
        inventory_[idx] = NULL;
        std::cout << BLUE "Unequipped position: " << idx << RESET << std::endl;
        count_++;
        if (count_ == 100)
            std::cout << BLUE "Unequipped storage full" RESET << std::endl;
    }
    else
        std::cout << BLUE "position to unequip out of range" << RESET << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory_[idx])
        inventory_[idx]->use(target);
    else if (!inventory_[idx])
        std::cout << BLUE "inventory position not equipped, use not possible" RESET << std::endl;
    else
        std::cout << BLUE "position to use out of range" << RESET << std::endl;
}