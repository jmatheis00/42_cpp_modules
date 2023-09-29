/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:31:33 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// srand() different numbers for each execution -> sets seed for rand()
//  time(NULL) returns no of seconds sind 1970 --> always different
//  calling srand() with different numbers--> different random numbers
Base *generate(void)
{
    std::srand(std::time(NULL));
    int random = (std::rand() % 99) + 1;

    if (random % 3 == 0)
        return (new (A));
    else if (random % 3 == 1)
        return (new (B));
    else if (random % 3 == 2)
        return (new (C));
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << PURPLE "Type is A" RESET << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << PURPLE "Type is B" RESET << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << PURPLE "Type is C" RESET << std::endl;
    else
        std::cout << "cannot identify type" << std::endl;
}

// failing dynamic cast to a reference throws a bad_cast exception
void identify(Base &p)
{
    bool istype = 0;
    try
    {
        (Base) dynamic_cast<A &>(p);
        std::cout << BLUE << "Type is A" << RESET << std::endl;
        istype = 1;
    }
    catch (std::bad_cast)
    {
    }
    try
    {
        (Base) dynamic_cast<B &>(p);
        std::cout << BLUE << "Type is B" << RESET << std::endl;
        istype = 1;
    }
    catch (std::bad_cast)
    {
    }
    try
    {
        (Base) dynamic_cast<C &>(p);
        std::cout << BLUE << "Type is C" << RESET << std::endl;
        istype = 1;
    }
    catch (std::bad_cast)
    {
    }
    if (istype == 0)
        std::cout << "cannot identify type" << std::endl;
}

int main()
{
    Base *b1 = generate();
    identify(b1);
    identify(*b1);

    delete b1;

    return (0);
}