/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/26 13:03:06 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    {
        std::cout << YELLOW "SPAN TEST" RESET << std::endl;
        Span sp(10);

        sp.addNumber(3);
        sp.addNumber(8);
        sp.addNumber(22);
        sp.addNumber(45);

        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;

    }
    return 0;
}
