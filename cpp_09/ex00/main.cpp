/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/12 19:06:41 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// must use database in csv format which represents bitcoin price over time
// this database is provided with this subject
// takes as input a second database, storing the different prices/dates to evaluate
// using map
int main(int ac, char* ag[])
{
    std::ifstream infile;
    infile.open(ag[1]);
    if (ac != 2 || !infile.is_open())
        std::cout << "Error: could not open file" << std::endl;
    else
    {
        BitcoinExchange b(infile);
        
    }
    return 0;
}
