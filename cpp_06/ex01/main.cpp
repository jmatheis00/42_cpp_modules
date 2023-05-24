/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/24 11:18:42 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    std::cout << GREEN "data that should get serialized" RESET << std::endl;
    Data d;
    d.age = 55;
    d.name = "Bob";
    std::cout << "Name: " << d.name << ", age: " << d.age << std::endl;

    uintptr_t u = Serializer::serialize(&d);
    std::cout << GREEN "Data is serialized under the following number: " RESET << std::endl;
    std::cout << u << std::endl;

    Data* second = Serializer::deserialize(u);
    std::cout << GREEN "data in new struct after deserialized" RESET << std::endl;
    std::cout << "Name: " << second->name << ", age: " << second->age << std::endl;
    
    // std::cout << PURPLE "Comparison of addresses" RESET << std::endl;
    // std::cout << YELLOW "Original address:\t" << &d << RESET << std::endl;
    // std::cout << YELLOW "Address second struct:\t" << &(*second) << RESET << std::endl;

    return 0;
}