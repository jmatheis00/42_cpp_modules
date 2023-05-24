/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/24 09:13:54 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    Serializer s;

    std::cout << GREEN "data that should get serialized" RESET << std::endl;
    Data d;
    d.age = 55;
    d.name = "Bob";
    std::cout << "Name: " << d.name << ", age: " << d.age << std::endl;

    uintptr_t u = s.serialize(&d);
    std::cout << GREEN "Data is serialized under the following number: " RESET << std::endl;
    std::cout << u << std::endl;

    Data* second = s.deserialize(u);
    std::cout << GREEN "data in new struct after deserialized" RESET << std::endl;
    std::cout << "Name: " << second->name << ", age: " << second->age << std::endl;
    
    std::cout << PURPLE "Comparison of addresses" RESET << std::endl;
    std::cout << YELLOW "Original address:\t" << &d << RESET << std::endl;
    std::cout << YELLOW "Address second struct:\t" << &(*second) << RESET << std::endl;
    // address second points to

    return 0;
}