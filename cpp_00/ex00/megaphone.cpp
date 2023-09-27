/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:05:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:06:24 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// convert lowercase to uppercase
int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        for (int i = 1; argv[i]; i++)
        {
            std::string buff = argv[i];
            for (int count = 0; buff[count]; count++)
                buff[count] = std::toupper(buff[count]);
            std::cout << buff;
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}