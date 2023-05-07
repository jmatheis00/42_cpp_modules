/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:47:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/07 23:01:34 by jmatheis         ###   ########.fr       */
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
int main()
{
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());

    // ICharacter* me = new Character("me");

    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // ICharacter* bob = new Character("bob");
    // std::cout << RED "DEEP COPY CHECK" RESET << std::endl;
    // AMateria* deep;
    // deep = src->createMateria("sss");
    // me->equip(deep);
    // deep = src->createMateria("ice");
    // me->equip(deep);

    // me->use(2, *bob);
    // me->use(3, *bob);

    // me->use(2, *bob);
    // me->use(3, *bob);

    // // me->use(0, *bob);
    // // me->use(1, *bob);

    // delete bob;
    // delete me;
    // delete src;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return (0);
}