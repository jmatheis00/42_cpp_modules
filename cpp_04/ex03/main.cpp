/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:47:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:26:19 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// Materias have types (e.g. Ice, cure, fire, ...)
// make deep copy test
// test if inventory is full or uninitialized materia is used
int main()
{
    {
        std::cout << YELLOW "MAIN FROM SUBJECT" RESET << std::endl;
        // learn Materia from Source (that they are known)
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        // Create Character that can use the Materias
        ICharacter *me = new Character("me");
        // create Materia with specific type and put
        // them in the inventory of the character
        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        // create Character that gets attacked
        ICharacter *bob = new Character("bob");
        std::cout << PURPLE "OUTPUT" RESET << std::endl;
        me->use(0, *bob);
        me->use(1, *bob);
        std::cout << PURPLE "Destructors" RESET << std::endl;
        delete bob;
        delete me;
        delete src;
    }
    {
        std::cout << YELLOW "Error Testing" RESET << std::endl;
        IMateriaSource *src = new MateriaSource();
        Character *me = new Character("me");

        for (int i = 0; i < 4; i++)
            src->learnMateria(new Ice());

        std::cout << PURPLE "Full SourceInventory" RESET << std::endl;
        Cure *cured = new Cure();
        src->learnMateria(cured);

        std::cout << PURPLE "unlearned Materia tried to create" RESET << std::endl;
        AMateria *tmp;
        tmp = src->createMateria("cure");

        std::cout << PURPLE "uncreated Materia tried to equip" RESET << std::endl;
        me->equip(tmp);

        std::cout << PURPLE "Equip inventory" RESET << std::endl;
        for (int i = 0; i < 4; i++)
        {
            AMateria *tmp1 = src->createMateria("ice");
            me->equip(tmp1);
        }

        std::cout << PURPLE "fully equipped inventory" RESET << std::endl;
        AMateria *tmp2 = src->createMateria("ice");
        me->equip(tmp2);

        std::cout << PURPLE "current inventory" RESET << std::endl;
        me->print_inventory();

        std::cout << PURPLE "unequip() out of range" RESET << std::endl;
        me->unequip(4);

        std::cout << PURPLE "unequip() working" RESET << std::endl;
        me->unequip(2);
        me->print_inventory();

        std::cout << PURPLE "use() no materia exists at this position" RESET << std::endl;
        ICharacter *bob = new Character("bob");
        me->use(2, *bob);

        std::cout << PURPLE "use() out of range" RESET << std::endl;
        me->use(4, *bob);

        std::cout << PURPLE "use() working" RESET << std::endl;
        me->use(3, *bob);

        std::cout << YELLOW "\nDeep copy Testing" RESET << std::endl;
        Character *other = new Character(*me);
        Character diff;
        diff = *me;

        std::cout << PURPLE "me inventory" RESET << std::endl;
        me->print_inventory();
        std::cout << PURPLE "other inventory" RESET << std::endl;
        other->print_inventory();
        std::cout << PURPLE "diff inventory" RESET << std::endl;
        diff.print_inventory();

        AMateria *tmp3 = src->createMateria("ice");
        me->equip(tmp3);
        me->unequip(3);

        std::cout << PURPLE "me inventory MUST BE DIFFERENT" RESET << std::endl;
        std::cout << PURPLE "me inventory" RESET << std::endl;
        me->print_inventory();
        std::cout << PURPLE "other inventory" RESET << std::endl;
        other->print_inventory();
        std::cout << PURPLE "diff inventory" RESET << std::endl;
        diff.print_inventory();

        std::cout << PURPLE "Destructors" RESET << std::endl;
        delete bob;
        delete tmp2;
        delete cured;
        delete me;
        delete other;
        delete src;
    }
    return (0);
}