/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/19 11:40:09 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// turn in more tests!
int main()
{
    {
        std::cout << YELLOW "\nANIMAL & DOG & CAT TEST" RESET << std::endl;
        std::cout << PURPLE "Destructors" RESET << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << PURPLE "Types" RESET << std::endl;
        std::cout << meta->getType() << std::endl;
        std::cout << j->getType() << std::endl;
        std::cout << i->getType() << std::endl;
        std::cout << PURPLE "Sounds" RESET << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        std::cout << PURPLE "Destructors" RESET << std::endl;
        delete meta;
        delete j;
        delete i;
    }
    {
        std::cout << YELLOW "\nWRONGCAT & WRONGANIMAL TEST" RESET << std::endl;
        std::cout << PURPLE "Constructors" RESET << std::endl;
        const WrongAnimal* Wrongy = new WrongAnimal();
        const WrongAnimal* Writty = new WrongCat();
        std::cout << PURPLE "Types" RESET << std::endl;
        std::cout << Writty->getType() << std::endl;
        std::cout << Wrongy->getType() << std::endl;
        std::cout << PURPLE "Sounds" RESET << std::endl;
        Writty->makeSound(); //won't output the cat sound!
        Wrongy->makeSound();
        std::cout << PURPLE "Destructors" RESET << std::endl;
        delete Wrongy;
        delete Writty;
    }
    {
        std::cout << YELLOW "\nNO POLYMORPHISM WRONGCAT" RESET << std::endl;
        std::cout << PURPLE "Constructors" RESET << std::endl;
        const WrongAnimal* Wrongy = new WrongAnimal();
        const WrongCat *Writty = new WrongCat();
        std::cout << PURPLE "Types" RESET << std::endl;
        std::cout << Writty->getType() << std::endl;
        std::cout << Wrongy->getType() << std::endl;
        std::cout << PURPLE "Sounds" RESET << std::endl;
        Writty->makeSound(); //won't output the cat sound!
        Wrongy->makeSound();
        std::cout << PURPLE "Destructors" RESET << std::endl;
        delete Wrongy;
        delete Writty;
    }
    return 0;
}