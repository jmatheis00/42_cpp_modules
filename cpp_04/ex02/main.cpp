/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/28 16:46:59 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

// turn in more tests!
int main()
{
    // std::cout << YELLOW "Error test: Animal as abstract base class" RESET << std::endl;
    // Animal test;
    std::cout << YELLOW "Animal array test" RESET << std::endl;
    const Animal* j[8];
    std::cout << PURPLE "Constructors" RESET << std::endl;   
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
            j[i] = new Dog();
        else
            j[i] = new Cat();
    }
    std::cout << PURPLE "Types & Sounds" RESET << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << j[i]->getType() << std::endl;
        j[i]->makeSound();
    }
    std::cout << PURPLE "Destructors" RESET << std::endl;   
    for (int i = 0; i < 8; i++)
        delete j[i];

    std::cout << YELLOW "Deep copy test" RESET << std::endl;
    std::cout << PURPLE "Constructors Bello" RESET << std::endl;   
    Dog* Bello = new Dog();
    std::cout << PURPLE "Brain for Bello" RESET << std::endl;
    Bello->setidea(0, "Hello from idea 1");
    Bello->setidea(1, "Hello from idea 2");
    Bello->setidea(2, "Hello from idea 3");
    Bello->setidea(3, "Hello from idea 4");
    Bello->setidea(4, "Hello from idea 5");
    for(int i = 0; i < 5; i++)
        std::cout << Bello->getidea(i) << std::endl;

    Dog* Luna = new Dog(*Bello);
    std::cout << PURPLE "Brain for Luna" RESET << std::endl;   
    for(int i = 0; i < 5; i++)
        std::cout << Luna->getidea(i) << std::endl;
    Bello->setidea(1, "This is the new second idea 2");
    std::cout << PURPLE "Compare Bello's with Luna's second idea'" RESET << std::endl;
    std::cout << Bello->getidea(1) << std::endl;
    std::cout << Luna->getidea(1) << std::endl; //should be unchanged/independent
    std::cout << PURPLE "Destructors for Bello and Luna" RESET << std::endl;
    delete (Bello);
    delete (Luna);
    return 0;
}