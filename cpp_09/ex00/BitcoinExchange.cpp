/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/13 11:20:54 by jmatheis         ###   ########.fr       */
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
        if (buff != "date | value")
        {
            size_t delim = buff.find("|");
            std::string value = buff.substr(delim + 1, buff.length());
            float val_f = strtod(value.c_str(), NULL);
            if (delim == std::string::npos)
                delim = buff.length();
            std::string date = buff.substr(0, delim);
            if (checkDate(buff) == false || buff.find("|") == std::string::npos)
                std::cout << RED "Error: bad input => " << buff << RESET;
            else if (checkValue(val_f) == 0)
            {
                std::cout << date << " => ";
                std::cout << val_f;
                checkExchangeRate(date, val_f);
            }
            else if (checkValue(val_f) == -1)
                std::cout << RED "Error: not a positive number." RESET;
            else if (checkValue(val_f) == -2)
                std::cout << RED "Error: too large a number." RESET;
            std::cout << std::endl;
        }
    }
    infile.close();
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

    yearf_ = strtod(year.c_str(), NULL);
    monthf_ = strtod(month.c_str(), NULL);
    dayf_ = strtod(day.c_str(), NULL);

    if(yearf_ > 1900 + timeunit->tm_year || yearf_ < 0
        || monthf_ > 12 || monthf_ < 0 || dayf_ > 31 || dayf_ < 0
        || (yearf_ == 1900 + timeunit->tm_year && monthf_ > 1 + timeunit->tm_mon)
        || (yearf_ == 1900 + timeunit->tm_year && monthf_ == 1 + timeunit->tm_mon
            &&  dayf_ > timeunit->tm_mday))
        return(false);
    return(true);
}

int BitcoinExchange::checkValue(float val_f)
{
    if (val_f < 0)
        return(-1);
    if (val_f > 1000)
        return(-2);
    return (0);
}

void BitcoinExchange::checkExchangeRate(std::string date, float val_f)
{
    std::map<std::string, float>::const_iterator it = map_.lower_bound(date);
    
    size_t delim1 = map_.begin()->first.find("-");
    size_t delim2 = map_.begin()->first.find("-", map_.begin()->first.find("-") + 1);
    std::string y = map_.begin()->first.substr(0, delim1);
    std::string m = map_.begin()->first.substr(delim1 + 1, delim2);
    std::string d = map_.begin()->first.substr(delim2 + 1, map_.begin()->first.find(","));
    float yf = strtod(y.c_str(), NULL);
    float mf = strtod(m.c_str(), NULL);
    float df = strtod(d.c_str(), NULL);
    if (yearf_ < yf || (yearf_ == yf && monthf_ < mf) || (yearf_ == yf && monthf_ == mf && dayf_ < df))
    {
        std::cout << RED " NO EXCHANGE RATE FOUND, DATE TOO OLD" RESET;
        return ;
    }
    if (it != map_.end() && it->first == date)
    {
        std::cout << " = " << val_f * it->second;
        return ;
    }
    else if (it != map_.end() && it->first != date)
    {
        it--;
        std::cout << " = " << val_f * it->second;
    }
}