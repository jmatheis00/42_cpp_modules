/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:37:38 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char *ag[])
{
    if (ac != 2)
        std::cout << RED "Error: wrong number of arguments" RESET << std::endl;
    else
    {
        RPN r(ag[1]);
        if (r.CheckCharacters() == false)
        {
            std::cout << RED "Error: invalid characters" RESET << std::endl;
            return (1);
        }
        try
        {
            r.Split();
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    return 0;
}
