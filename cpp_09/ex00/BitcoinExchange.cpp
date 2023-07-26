/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/07/26 10:33:38 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "Default Constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copyclass)
{
    *this = copyclass;
}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& copyop)
{
    if (this != &copyop)
    {
        map_ = copyop.map_;
    }
    return(*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

// Check both files if opening is possible
BitcoinExchange::BitcoinExchange(std::string& infile) : infile_(infile)
{
    data_.open("./data.csv");
    if (!data_.is_open())
    {
        std::cout << "data.csv: ";
        throw CouldNotOpenFile();
    }
    if (!infile_.is_open())
    {
        data_.close();
        std::cout << infile << ": ";
        throw CouldNotOpenFile();       
    }
}

// Fill map with date & exchange_rate
void BitcoinExchange::getDatabase()
{
    std::string buff;
    while(getline(data_, buff))
    {
        if (buff != "date,exchange_rate")
        {
            size_t delim = buff.find(',');
            if (delim == std::string::npos || buff.find('-') == std::string::npos
                || buff.find('-', buff.find('-') + 1) == std::string::npos
                || checkDate(buff.substr(0, buff.find(','))) == false
                || buff.substr(buff.find(',') + 1, buff.length()) == ""
                || checkFloatValue(buff.substr(buff.find(',') + 1, buff.length())) == -1)
            {
                std::cout << "data.csv: ";
                throw FormatError();
            }
            std::string numb = buff.substr((delim + 1), buff.length());
            map_.insert(std::make_pair(buff.substr(0, delim), strtod(numb.c_str(), NULL)));
        }
    }
    data_.close();
}

// check infile for
// 1. valid delimiters all existing
// 2. valid Date
// 3. Float value valid (between 0 and 1000) -> get exchange rate
// 4. Float value negative
// 5. Float value > 1000
void BitcoinExchange::MainProccess()
{   
    std::string buff;
    while(getline(infile_, buff))
    {
        if (buff != "date | value")
        {
            if (checkInputDelimiters(buff) == false)
                std::cout << RED "Error: bad input => " RESET << buff;
            else if (checkDate(buff.substr(0, buff.find('|'))) == false)
                std::cout << RED "Error: bad input => " RESET << buff;
            else if (checkFloatValue(buff.substr(buff.find('|') + 1, buff.length())) == 0)
            {
                std::string value = buff.substr(buff.find('|') + 1, buff.length());
                float valf = strtod(value.c_str(), NULL);
                
                std::string date;
                if (buff[buff.find('|')-1] == ' ')
                    date = buff.substr(0, buff.find('|')-1);
                else
                    date = buff.substr(0, buff.find('|'));

                if (checkExchangeRate(valf, date) == false)
                    std::cout << RED "Error: bad input (date too old) => " RESET << buff;
            }
            else if (checkFloatValue(buff.substr(buff.find('|') + 1, buff.length())) == -1)
                std::cout << RED "Error: not a positive number." RESET;
            else if (checkFloatValue(buff.substr(buff.find('|') + 1, buff.length())) == -2)
                std::cout << RED "Error: too large a number." RESET;
            std::cout << std::endl;
        }
    }   
    infile_.close();
}

// Checking for delimiters (Bad input), invalid syntax of number
bool BitcoinExchange::checkInputDelimiters(std::string buff)
{
    if (buff.find('-') == std::string::npos
        || buff.find('-', buff.find('-') + 1) == std::string::npos
        || buff.find('|', buff.find('-', buff.find('-') + 1) + 1) == std::string::npos)
        return(false);
    unsigned int numb = buff.find('|', buff.find('-', buff.find('-') + 1) + 1) + 1;
    while(buff[numb] == ' ')
        numb++;
    if (buff[numb] == '\0')
        return(false);
    if ((std::isdigit(buff[numb]) == false && buff[numb] != '-')
        || (buff[numb] == '-' && std::isdigit(buff[numb+1]) == false))
        return(false);
    return (true);
}

// date must be in the past or present and valid
// handle leap years and different no of days per month
// handle future dates
bool BitcoinExchange::checkDate(std::string date)
{
    // GET YEAR MONTH AND DAY
    std::string y = date.substr(0, date.find('-'));
    float year = strtod(y.c_str(), NULL);
    std::string m = date.substr(date.find('-') + 1, date.find('-', date.find('-') + 1));
    float month = strtod(m.c_str(), NULL);
    std::string d = date.substr(date.find('-', date.find('-') + 1) + 1, date.size());
    float day = strtod(d.c_str(), NULL);

    time_t now;
	std::time(&now);
	tm *timeunit = localtime(&now);

    if(year > 1900 + timeunit->tm_year || year < 0
        || month > 12 || month < 1 || day > 31 || day < 1
        || (year == 1900 + timeunit->tm_year && month > 1 + timeunit->tm_mon)
        || (year == 1900 + timeunit->tm_year && month == 1 + timeunit->tm_mon
            &&  day > timeunit->tm_mday))
        return(false);
    if (((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        || (month == 2 && day > 29) || (month == 2 && static_cast<int>(year) % 4 == 0 
            && static_cast<int>(year) % 100 != 0 && day > 28)
        || (month == 2 && static_cast<int>(year) % 400 == 0 && day > 28))
        return(false);
    return(true);
}

int BitcoinExchange::checkFloatValue(std::string value)
{
    float floatval = strtod(value.c_str(), NULL);
    if (floatval < 0)
        return(-1);
    if (floatval > 1000)
        return(-2);
    return (0);
}

// check exchange rate and if date is not too old
// lower_bound : returns first element that is not less than date
bool BitcoinExchange::checkExchangeRate(float valf, std::string date)
{
    std::map<std::string, float>::const_iterator it = map_.lower_bound(date);
    if (it != map_.end() && it->first == date)
        std::cout << date << " => " << valf << " = " << valf * it->second;
    else if (it->first != date)
    {
        if (it == map_.begin())
            return (false);
        it--;
        std::cout << date << " => " << valf << " = " << valf * it->second;
    }
    return (true);
}

// EXCEPTION FUNCTIONS
const char* BitcoinExchange::CouldNotOpenFile::what() const throw()
{
	return("Could not open file!");
}

const char* BitcoinExchange::FormatError::what() const throw()
{
	return("Wrong format in file!");
}