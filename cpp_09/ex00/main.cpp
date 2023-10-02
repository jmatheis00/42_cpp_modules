/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:37:17 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// must use database in csv format which represents bitcoin price over time
// this database is provided with this subject
// takes as input a second database, storing the different prices/dates to evaluate
// using map
// one argument: input.csv
int main(int ac, char *ag[])
{
    if (ac != 2)
        std::cout << "Error: Wrong number of arguments" << std::endl;
    else
    {
        std::string s = ag[1];
        try
        {
            BitcoinExchange b(s);
            b.getDatabase();
            b.MainProccess();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}
