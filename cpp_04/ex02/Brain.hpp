/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:56:38 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:23:37 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define RESET "\033[0m"   /* Reset */
#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define PURPLE "\033[35m" /* Purple */

class Brain
{
private:
    std::string ideas_[100];

public:
    Brain();                               // Default Constructor
    Brain(const Brain &copyclass);         // Copy Constructor
    Brain &operator=(const Brain &copyop); // copy assignment operator
    ~Brain();                              // Destructor

    std::string get_idea(int i);
    void set_idea(int i, std::string content);
};

#endif