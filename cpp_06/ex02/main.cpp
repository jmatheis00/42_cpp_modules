/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/15 20:51:50 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//srand() different numbers for each execution
// time(NULL) returns no of seconds sind 1970 --> always different
Base* generate(void)
{
    /* using nano-seconds instead of seconds */
    struct timespec timesp;
    clock_gettime(CLOCK_MONOTONIC, &timesp);
    srand((time_t)timesp.tv_nsec);
    // srand(time(NULL));
	int random = rand() % 3;

	if (random == 0)
		return(new (A));
	else if (random == 1)
		return(new (B));
	else if (random == 2)
		return(new (C));
	return(NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << PURPLE "Actual type is A" RESET << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << PURPLE "Actual type is B" RESET << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << PURPLE "Actual type is C" RESET << std::endl;
	else
        std::cout << "Error while generating" << std::endl;
}

// void identify(Base& p)
// {
    // should use try and catch block to 
    // check if cast failed
// // 	// A, B or C??? is base pointing to
// // 	// no pointer allowed inside the function
// // 	// no typeinfo
// }

int main()
{
    {
        Base* b1 = generate();
        Base* b2 = generate();
        Base* b3 = generate();
        Base* b4 = generate();
        Base* b5 = generate();

        identify(b1);
        identify(b2);
        identify(b3);
        identify(b4);
        identify(b5);

        delete b1;
        delete b2;
        delete b3;
        delete b4;
        delete b5;
    }
	// p->identify(*p);
	// p1->identify(*p1);

	return (0);
}