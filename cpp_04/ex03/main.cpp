/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:47:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/08 20:00:48 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// https://www.google.com/search?q=character+equip+materia&client=safari&rls=en&ei=TRFYZMfcMuuUxc8PiomLkAY&ved=0ahUKEwiHt6fwjOT-AhVrSvEDHYrEAmIQ4dUDCA8&uact=5&oq=character+equip+materia&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQAzIFCCEQoAEyBQghEKABMgUIIRCgAToKCAAQRxDWBBCwAzoLCC4QgAQQsQMQgwE6CwgAEIAEELEDEIMBOhEILhCABBCxAxCDARDHARDRAzoICC4QgAQQsQM6CwguEIAEEMcBEK8BOg4ILhCKBRCxAxCDARDUAjoLCC4QigUQsQMQgwE6GQguEIAEELEDEIMBEJcFENwEEN4EEN8EGAE6BwgAEIoFEEM6CAgAEIAEELEDOgsIABCKBRCxAxCDAToLCC4QgwEQsQMQgAQ6GQguEIMBELEDEIAEEJcFENwEEN4EEN8EGAE6BwguEIoFEEM6BQgAEIAEOhMIABANEIAEELEDEIMBELEDEIMBOg0IABANEIAEELEDEIMBOgoIABANEIAEELEDOhAIABANEIAEELEDEIMBELEDOhAIABANEIAEELEDELEDEIMBOgcIABANEIAEOgkIABANEIAEEAo6DQgAEA0QgAQQsQMQsQM6BwgAEIAEEAo6BwgAEBMQgAQ6CAgAEBYQHhATOgoIABAWEB4QDxATOgYIABAWEB46CAgAEBYQHhAKOggIABAWEB4QDzoICCEQFhAeEB06CgghEBYQHhAPEB06BAghEBU6BwghEKABEApKBAhBGABQ7QxYw0NgyUtoDXABeACAAaEBiAGvGJIBBTEzLjE1mAEAoAEByAEIwAEB2gEGCAEQARgU&sclient=gws-wiz-serp
// Materias have types (e.g. Ice, cure, fire, ...)
// make deep copy test
// test if inventory is full or uninitialized materia is used

void testing()
{
    {
        std::cout << YELLOW "MAIN FROM SUBJECT" RESET << std::endl;
        // learn Materia from Source (that they exist)
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        // Create Character that can use the Materias
        ICharacter* me = new Character("me");
        // create Materia with specific type and put
        // them in the inventory of the character
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        // create Character that gets attacked
        ICharacter* bob = new Character("bob");
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
        IMateriaSource* src = new MateriaSource();
        // ONE LEAK FROM HERE
        for (int i = 0; i < 4; i++)
            src->learnMateria(new Ice());
        
        // ONE TEST
        IMateriaSource* src2 = new MateriaSource();
            src2->learnMateria(new Ice());
        //  SECOND TEST (uncreated materia)
        AMateria* tmp;
        tmp = src->createMateria("cure");

        Character* me = new Character("me");
        for (int i = 0; i < 4; i++)
        {
            AMateria* tmp1 = src->createMateria("ice");
            me->equip(tmp1);
        }
        me->equip(tmp);

        std::cout << PURPLE "current inventory" RESET << std::endl;
        me->print_inventory();
        me->unequip(2);
        me->print_inventory();
        me->equip(tmp);
        me->print_inventory();

        std::cout << YELLOW "Deep copy Testing" RESET << std::endl;
        Character* other = new Character(*me);
        Character diff;
        diff = *me;
        std::cout << PURPLE "me inventory" RESET << std::endl;
        me->print_inventory();
        std::cout << PURPLE "other inventory" RESET << std::endl;
        other->print_inventory();
        std::cout << PURPLE "diff inventory" RESET << std::endl;
        diff.print_inventory();

        me->unequip(4);
        me->unequip(3);
        std::cout << PURPLE "me inventory MUST BE DIFFERENT" RESET << std::endl;
        std::cout << PURPLE "me inventory" RESET << std::endl;
        me->print_inventory();
        std::cout << PURPLE "other inventory" RESET << std::endl;
        other->print_inventory();
        std::cout << PURPLE "diff inventory" RESET << std::endl;
        diff.print_inventory();

        std::cout << PURPLE "Me Destructors" RESET << std::endl;
        delete me;
        std::cout << PURPLE "other Destructors" RESET << std::endl;
        delete other;
        std::cout << PURPLE "source Destructors" RESET << std::endl;
        delete src;
        delete src2;
        std::cout << PURPLE "diff Destructors" RESET << std::endl;
    }
}

int main()
{
     {
        std::cout << YELLOW "MAIN FROM SUBJECT" RESET << std::endl;
        // learn Materia from Source (that they exist)
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        // Create Character that can use the Materias
        ICharacter* me = new Character("me");
        // create Materia with specific type and put
        // them in the inventory of the character
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        // create Character that gets attacked
        ICharacter* bob = new Character("bob");
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
        IMateriaSource* src = new MateriaSource();
        for (int i = 0; i < 4; i++)
            src->learnMateria(new Ice());

        std::cout << PURPLE "Full SourceInventory" RESET << std::endl;
        IMateriaSource* src2 = new MateriaSource();
            src2->learnMateria(new Ice());

        std::cout << PURPLE "unlearned Materia tried to create" RESET << std::endl;
        AMateria* tmp;
        tmp = src->createMateria("cure");

        Character* me = new Character("me");
        for (int i = 0; i < 4; i++)
        {
            AMateria* tmp1 = src->createMateria("ice");
            me->equip(tmp1);
        }

        std::cout << PURPLE "full equipped inventory" RESET << std::endl;
        me->equip(tmp);

        std::cout << PURPLE "current inventory" RESET << std::endl;
        me->print_inventory();

        std::cout << PURPLE "unequip() out of range" RESET << std::endl;
        me->unequip(4);

        std::cout << PURPLE "unequip() working" RESET << std::endl;
        me->unequip(2);
        me->print_inventory();
        AMateria* tmp1 = src->createMateria("ice");
        me->equip(tmp1);
        me->print_inventory();

        std::cout << YELLOW "Deep copy Testing" RESET << std::endl;
        Character* other = new Character(*me);
        Character diff;
        diff = *me;

        std::cout << PURPLE "me inventory" RESET << std::endl;
        me->print_inventory();
        std::cout << PURPLE "other inventory" RESET << std::endl;
        other->print_inventory();
        std::cout << PURPLE "diff inventory" RESET << std::endl;
        diff.print_inventory();

        me->unequip(3);

        std::cout << PURPLE "me inventory MUST BE DIFFERENT" RESET << std::endl;
        std::cout << PURPLE "me inventory" RESET << std::endl;
        me->print_inventory();
        std::cout << PURPLE "other inventory" RESET << std::endl;
        other->print_inventory();
        std::cout << PURPLE "diff inventory" RESET << std::endl;
        diff.print_inventory();

        std::cout << PURPLE "Me Destructors" RESET << std::endl;
        delete me;
        std::cout << PURPLE "other Destructors" RESET << std::endl;
        delete other;
        std::cout << PURPLE "source Destructors" RESET << std::endl;
        delete src;
        delete src2;
        std::cout << PURPLE "diff Destructors" RESET << std::endl;
    }
    return (0);
}