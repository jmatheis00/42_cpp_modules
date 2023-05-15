/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/15 16:14:34 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(int ac, char *ag[])
{
    if (ac != 2)
    {
        std::cout << "invalid number of arguments" << std::endl;
        return (EXIT_FAILURE);
    }
    Serializer sc;
    sc = static_cast<Serializer> (sc);

    struct Data d;
    d.age = 55;
    d.name = ag[1];
    std::cout << "Name: " << d.name << ", age: " << d.age << std::endl;

    std::cout << "Original address:\t" << &d << std::endl;
    uintptr_t u = sc.serialize(&d);
    std::cout << "uintptr_t: " << u << std::endl;

    Data* second;
    second = sc.deserialize(u);
    std::cout << "Address after:\t\t" << second << std::endl;
    std::cout << "Name: " << second->name << ", age: " << second->age << std::endl;
    return 0;
}