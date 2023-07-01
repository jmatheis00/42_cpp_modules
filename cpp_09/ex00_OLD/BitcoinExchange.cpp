/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/13 12:20:51 by jmatheis         ###   ########.fr       */
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

    if (checkDatabase() == false)
        return ;
    while(getline(infile, buff))
    {
        if (buff != "date | value")
        {
            if (initAttributes(buff) == false
                || DateIsValid() == false
                || buff.find("|") == std::string::npos)
                std::cout << RED "Error: bad input => " << buff << RESET;
            else if (checkFloatValue() == 0)
            {
                std::cout << date_ << " => ";
                std::cout << valf_;
                checkExchangeRate();
            }
            else if (checkFloatValue() == -1)
                std::cout << RED "Error: not a positive number." RESET;
            else if (checkFloatValue() == -2)
                std::cout << RED "Error: too large a number." RESET;
            std::cout << std::endl;
        }
    }
    infile.close();
}

// CHECK FOR FILE WITH .CSV END
bool BitcoinExchange::checkDatabase()
{
    std::ifstream data;
    std::string buff;

    data.open("./data.csv");
    if (!data.is_open())
    {
        std::cout << "Error: could not open DATA file" << std::endl;
        return(false);
    }
    while(getline(data, buff))
    {
        size_t delim = buff.find(",");
        if (delim == std::string::npos)
        {
            std::cout << "Error: Wrong format in data.csv" << std::endl;
            return(false);
        }
        std::string numb = buff.substr((delim + 1), buff.length());
        addElement(buff.substr(0, delim), strtod(numb.c_str(), NULL));
    }
    data.close();
    return(true);
}

bool BitcoinExchange::initAttributes(std::string buff)
{
    // GET VALUE AND DATE
    size_t delim = buff.find("|");
    value_ = buff.substr(delim + 1, buff.length());
    valf_ = strtod(value_.c_str(), NULL);

    if (delim == std::string::npos)
        delim = buff.length();
    date_ = buff.substr(0, delim);

    // GET NUMBERS OF DATE
    delim = buff.find("-");
    size_t delim2 = buff.find("-", delim + 1);

    if (delim == std::string::npos || delim2 == std::string::npos)
        return(false);

    std::string year = buff.substr(0, delim);
    std::string month = buff.substr(delim + 1, delim2);

    delim = buff.find("|", delim2 + 1);
    if (delim == std::string::npos)
        delim = buff.length();

    std::string day = buff.substr(delim2 + 1, delim);

    yearf_ = strtod(year.c_str(), NULL);
    monthf_ = strtod(month.c_str(), NULL);
    dayf_ = strtod(day.c_str(), NULL);
    return (true);
}

void BitcoinExchange::addElement(std::string s, float i)
{
    map_.insert(std::make_pair(s, i));
}

bool BitcoinExchange::DateIsValid()
{
    time_t now;
	std::time(&now);

	tm *timeunit = localtime(&now);

    if(yearf_ > 1900 + timeunit->tm_year || yearf_ < 0
        || monthf_ > 12 || monthf_ < 0 || dayf_ > 31 || dayf_ < 0
        || (yearf_ == 1900 + timeunit->tm_year && monthf_ > 1 + timeunit->tm_mon)
        || (yearf_ == 1900 + timeunit->tm_year && monthf_ == 1 + timeunit->tm_mon
            &&  dayf_ > timeunit->tm_mday))
        return(false);
    return(true);
}

int BitcoinExchange::checkFloatValue()
{
    if (valf_ < 0)
        return(-1);
    if (valf_ > 1000)
        return(-2);
    return (0);
}

void BitcoinExchange::checkExchangeRate()
{
    std::map<std::string, float>::const_iterator it = map_.lower_bound(date_);
    
    if(DateIsNotTooOld() == false)
        return ;
    if (it != map_.end() && it->first == date_)
        std::cout << " = " << valf_ * it->second;
    else if (it != map_.end() && it->first != date_)
    {
        it--;
        std::cout << " = " << valf_ * it->second;
    }
}

bool BitcoinExchange::DateIsNotTooOld()
{
    size_t delim1 = map_.begin()->first.find("-");
    size_t delim2 = map_.begin()->first.find("-", map_.begin()->first.find("-") + 1);
    std::string y = map_.begin()->first.substr(0, delim1);
    std::string m = map_.begin()->first.substr(delim1 + 1, delim2);
    std::string d = map_.begin()->first.substr(delim2 + 1, map_.begin()->first.find(","));
    float yf = strtod(y.c_str(), NULL);
    float mf = strtod(m.c_str(), NULL);
    float df = strtod(d.c_str(), NULL);

    if (yearf_ < yf
        || (yearf_ == yf && monthf_ < mf)
        || (yearf_ == yf && monthf_ == mf && dayf_ < df))
    {
        std::cout << RED " NO EXCHANGE RATE FOUND, DATE TOO OLD" RESET;
        return(false);
    }
    return(true);
}