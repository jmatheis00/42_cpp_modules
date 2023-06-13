/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/13 12:53:20 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char* ag[])
{
    if (ac != 2)
        std::cout << "Error: wrong number of arguments" << std::endl;
    else
    {
        RPN r(ag[1]);
        if (r.CheckCharacters() == false)
        {
            std::cout << "Error: invalid characters" << std::endl;
            return(1);
        }
        r.Split();
    }
    return 0;
}
