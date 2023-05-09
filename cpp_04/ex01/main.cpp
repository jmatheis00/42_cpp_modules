/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/09 13:10:39 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

// Copy Assignment Operator:
// already initialized object becomes another
// already initialized object by using equal operator
// Copy Constructor
    // Dog bello;
    // Animal idk;
    // idk = bello; // Copy Assignment Operator 
    // idk.makeSound();
int main()
{
    {
        std::cout << YELLOW "Animal array test" RESET << std::endl;
        const Animal* j[8];

        std::cout << PURPLE "Constructors" RESET << std::endl;   
        for (int i = 0; i < 8; i++)
        {
            if (i % 2 == 0)
            {
                std::cout << GREEN "new dog, array position: " << i << RESET << std::endl;
                j[i] = new Dog();
            }
            else
            {
                std::cout << GREEN "new cat, array position: " << i << RESET << std::endl;
                j[i] = new Cat();
            }
        }

        std::cout << PURPLE "Types & Sounds" RESET << std::endl;
        for (int i = 0; i < 8; i++)
        {
            std::cout << j[i]->getType() << std::endl;
            j[i]->makeSound();
        }

        std::cout << PURPLE "Destructors" RESET << std::endl;   
        for (int i = 0; i < 8; i++)
        {
             std::cout << PURPLE "Destructor array pos: " << i << RESET << std::endl;   
            delete j[i];
        }
    }

    // COPY TEST
    std::cout << YELLOW "\nDeep copy test" RESET << std::endl;
    std::cout << PURPLE "Constructors Bello" RESET << std::endl;   
    Dog* Bello = new Dog();
    std::cout << PURPLE "Bello's Brain" RESET << std::endl;
    Bello->setidea(0, "Hello from idea 1");
    Bello->setidea(1, "Hello from idea 2");
    Bello->setidea(2, "Hello from idea 3");
    Bello->setidea(3, "Hello from idea 4");
    Bello->setidea(4, "Hello from idea 5");
    for(int i = 0; i < 5; i++)
        std::cout << Bello->getidea(i) << std::endl;

    std::cout << PURPLE "Constructors Luna" RESET << std::endl;   
    Dog *Luna = new Dog(*Bello); // Calls Copy Constructor

    std::cout << PURPLE "Constructors Lucy" RESET << std::endl;   
    Dog Lucy;
    Lucy = *Bello; // Calls Copy Assignment Operator

    std::cout << PURPLE "Luna's Brain" RESET << std::endl;   
    for(int i = 0; i < 5; i++)
        std::cout << Luna->getidea(i) << std::endl;

    std::cout << PURPLE "Lucy's Brain" RESET << std::endl;   
    for(int i = 0; i < 5; i++)
        std::cout << Lucy.getidea(i) << std::endl;

    Bello->setidea(1, "This is the new second idea 2");

    std::cout << PURPLE "Comparison of second idea after change in Bello" RESET << std::endl;
    std::cout << "Bello's second idea:\t";
    std::cout << Bello->getidea(1) << std::endl;
    std::cout << "Luna's second idea:\t";
    std::cout << Luna->getidea(1) << std::endl; //should remain unchanged
    std::cout << "Lucy's second idea:\t";
    std::cout << Lucy.getidea(1) << std::endl; //should remain unchanged

    std::cout << PURPLE "Destructors" RESET << std::endl;
    delete (Bello);
    delete (Luna);    

    return (0);
}