/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/15 10:59:08 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char *ag[])
{
    if (ac != 2)
    {
        std::cout << "invalid number of arguments" << std::endl;
        return (EXIT_FAILURE);
    }
    ScalarConverter* sc = new ScalarConverter;
    sc = static_cast<ScalarConverter*> (sc);

    sc->convert(ag[1]);
    return 0;
}