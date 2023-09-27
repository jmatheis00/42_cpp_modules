/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:13:21 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:11:30 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */

class HumanA
{
private:
    std::string name_;
    Weapon &w_;

public:
    HumanA(std::string name, Weapon &w); // takes Weapon in Constructor
    ~HumanA();
    void attack();
};

#endif