/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:17 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/10 20:31:17 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

#define RESET       "\033[0m"
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();
        void set_name(std::string s);
        void announce(void);

};

Zombie* zombieHorde(int N, std::string name);
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif