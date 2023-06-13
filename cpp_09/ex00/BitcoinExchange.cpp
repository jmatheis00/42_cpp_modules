/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/13 09:42:44 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "Default Constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copyclass)
{
    *this = copyclass;
}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& copyop)
{
    if (this != &copyop)
    {

    }
    return(*this);
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Destructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::ifstream& infile)
{
    std::cout << "Constructor with infile" << std::endl;
    std::string buff;
    std::ifstream data;
    data.open("data.csv");
    if (!data.is_open())
    {
        std::cout << "Error: could not open DATA file" << std::endl;
        return ;
    }
    while(getline(data, buff))
    {
        std::string numb = buff.substr((buff.find(",") + 1), buff.length());
        addElement(buff.substr(0, buff.find(",")), strtod(numb.c_str(), NULL));
    }
    data.close();
    while(getline(infile, buff))
    {
        // DO EVERYTHING IN THIS LOOP
        if (buff != "date | value")
        {
            size_t delim = buff.find(" | ");
            if (delim == std::string::npos)
                delim = buff.length();
            std::string date = buff.substr(0, delim);
            if (checkDate(buff) == false)
                std::cout << RED "Error: bad input => " << date << RESET;
            else 
                std::cout << date << " => ";


            std::string tmp;
            if (buff.find("|") != std::string::npos)
                tmp = buff.substr(buff.find("|") + 1, buff.length());
            else
                tmp = "0";
            float f = strtod(tmp.c_str(), NULL);
            addElement(buff.substr(0, buff.find("|")), f);
            std::cout << std::endl;
        }
    }
    infile.close();
    // output();
}

void BitcoinExchange::output()
{
    std::string content;
    std::ifstream data;
    data.open("data.csv");
    if (!data.is_open())
        std::cout << "Error: could not open DATA file" << std::endl;
    std::multimap<std::string, float>::const_iterator it = map_.begin();
    while(it != map_.end())
    {
        std::cout << it->first << " => " << it->second << std::endl;
        while(getline(data, content))
        {
            if(content.find(it->first) != std::string::npos)
            {
                std::string tmp = content.substr(content.find(","), content.length());
                float f = strtod(tmp.c_str(), NULL);
                std::cout << " = " << it->second / f << std::endl;
            }
        }
        it++;
    }
    data.close();
}

void BitcoinExchange::addElement(std::string s, float i)
{
    map_.insert(std::make_pair(s, i));
}

void BitcoinExchange::printMap()
{
    std::map<std::string, float>::const_iterator it = map_.begin();
    while(it != map_.end())
    {
        std::cout << it->first << "\t" << it->second << std::endl;
        it++;
    }
}

bool BitcoinExchange::checkDate(std::string buff)
{
    time_t now;
	std::time(&now);

	tm *timeunit = localtime(&now);
    size_t delim = buff.find("-");
    size_t delim2 = buff.find("-", delim + 1);

    if (delim == std::string::npos || delim2 == std::string::npos)
        return(false);

    std::string year = buff.substr(0, delim);
    std::string month = buff.substr(delim + 1, delim2);

    delim = buff.find(" |", delim2 + 1);
    if (delim == std::string::npos)
        delim = buff.length();

    std::string day = buff.substr(delim2 + 1, delim);

    float year_f = strtod(year.c_str(), NULL);
    float month_f = strtod(month.c_str(), NULL);
    float day_f = strtod(day.c_str(), NULL);

    if(year_f > 1900 + timeunit->tm_year || year_f < 0
        || month_f > 12 || month_f < 0 || day_f > 31 || day_f < 0
        || (year_f == 1900 + timeunit->tm_year && month_f > 1 + timeunit->tm_mon)
        || (year_f == 1900 + timeunit->tm_year && month_f == 1 + timeunit->tm_mon
            &&  day_f > timeunit->tm_mday))
        return(false);
    // std::cout << "DATE: " << year_f << "  " << month_f << "   " << day_f << std::endl;
    return(true);
}
