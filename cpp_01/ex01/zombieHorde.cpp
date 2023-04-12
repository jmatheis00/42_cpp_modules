/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:21:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/12 14:20:55 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// calls Constructor for an array of [N] objects
Zombie* zombieHorde(int N, std::string name)
{
    Zombie *temp;

    temp = new Zombie[N];
    for(int i = 0; i < N; i++)
        temp[i].set_name(name);
    return (temp);
}
