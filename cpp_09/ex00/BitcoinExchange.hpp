/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/13 12:12:02 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <dirent.h>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

class BitcoinExchange
{
	public:
		~BitcoinExchange(); //Destructor
		BitcoinExchange(std::ifstream& infile);
		void addElement(std::string s, float i);
		bool DateIsValid();
		int	checkFloatValue();
		bool checkInputFormat(std::string line);
		void checkExchangeRate();
		bool checkDatabase();
	private:
		bool DateIsNotTooOld();
		bool initAttributes(std::string buff);
		BitcoinExchange(); //Default Constructor
		BitcoinExchange(const BitcoinExchange &copyclass); //Copy Constructor
		BitcoinExchange& operator= (const BitcoinExchange& copyop); //copy assignment operator
		std::map<std::string, float> map_;

		std::string value_;
		std::string date_;
		float valf_;

		float yearf_;
		float monthf_;
		float dayf_;
};

#endif