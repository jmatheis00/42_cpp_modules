/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:47:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/25 18:16:25 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
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
    std::cout << RED "DEEP COPY CHECK" RESET << std::endl;
    AMateria* deep;
    deep = src->createMateria("sss");
    me->equip(deep);
    deep = src->createMateria("ice");
    me->equip(deep);

    me->use(2, *bob);
    me->use(3, *bob);

    me->use(2, *bob);
    me->use(3, *bob);

    // me->use(0, *bob);
    // me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return (0);
}