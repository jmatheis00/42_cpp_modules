/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/07/01 16:46:48 by jmatheis         ###   ########.fr       */
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
        map_ = copyop.map_;
    }
    return(*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

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

// CHECK FOR FILE WITH .CSV END
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

void BitcoinExchange::MainProccess()
{   
    std::string buff;
    while(getline(infile_, buff))
    {
        if (buff != "date | value")
        {
            // Checking for delimiters (Bad input)
            if ( buff.find('-') == std::string::npos
                || buff.find('-', buff.find('-') + 1) == std::string::npos
                || buff.find('|', buff.find('-', buff.find('-') + 1) + 1) == std::string::npos)
                std::cout << RED "Error: bad input => " RESET << buff;
            else if (checkDate(buff.substr(0, buff.find('|'))) == false)
                std::cout << RED "Error: OTHER bad input => " << buff << RESET;
            else if (checkFloatValue(buff.substr(buff.find('|') + 1, buff.length())) == 0)
            {
                std::string value = buff.substr(buff.find('|') + 1, buff.length());
                float valf = strtod(value.c_str(), NULL);
                std::cout << buff.substr(0, buff.find('|')) << " => "
                << valf;
                checkExchangeRate(valf, buff.substr(0, buff.find('|')));
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
        || month > 12 || month < 0 || day > 31 || day < 0
        || (year == 1900 + timeunit->tm_year && month > 1 + timeunit->tm_mon)
        || (year == 1900 + timeunit->tm_year && month == 1 + timeunit->tm_mon
            &&  day > timeunit->tm_mday))
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

void BitcoinExchange::checkExchangeRate(float valf, std::string date)
{
    std::map<std::string, float>::const_iterator it = map_.lower_bound(date);
    
    if(DateIsNotTooOld(date) == false)
        return ;
    if (it != map_.end() && it->first == date)
        std::cout << " = " << valf * it->second;
    else if (it != map_.end() && it->first != date)
    {
        it--;
        std::cout << " = " << valf * it->second;
    }
}

bool BitcoinExchange::DateIsNotTooOld(std::string date)
{
    size_t delim1 = map_.begin()->first.find("-");
    size_t delim2 = map_.begin()->first.find("-", map_.begin()->first.find("-") + 1);
    std::string y = map_.begin()->first.substr(0, delim1);
    std::string m = map_.begin()->first.substr(delim1 + 1, delim2);
    std::string d = map_.begin()->first.substr(delim2 + 1, map_.begin()->first.find(","));
    float yf = strtod(y.c_str(), NULL);
    float mf = strtod(m.c_str(), NULL);
    float df = strtod(d.c_str(), NULL);

    // VYEARF MONTHF DAYF
    std::string ye = date.substr(0, date.find('-'));
    float year = strtod(ye.c_str(), NULL);
    std::string mo = date.substr(date.find('-') + 1, date.find('-', date.find('-') + 1));
    float month = strtod(mo.c_str(), NULL);
    std::string da = date.substr(date.find('-', date.find('-') + 1) + 1, date.size());
    float day = strtod(da.c_str(), NULL);
    
    if (year < yf
        || (year == yf && month < mf)
        || (year == yf && month == mf && day < df))
    {
        std::cout << RED " Error: no exchange rate found, date too old" RESET;
        return(false);
    }
    return(true);
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