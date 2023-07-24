/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/07/24 10:38:30 by jmatheis         ###   ########.fr       */
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
		BitcoinExchange(std::string& infile);

		bool checkDate(std::string date);
		bool checkInputDelimiters(std::string buff);

		int	checkFloatValue(std::string value);
		bool checkExchangeRate(float val, std::string date);

		void getDatabase();
		void MainProccess();
		class CouldNotOpenFile: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormatError: public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:

		BitcoinExchange(); //Default Constructor
		BitcoinExchange(const BitcoinExchange &copyclass); //Copy Constructor
		BitcoinExchange& operator= (const BitcoinExchange& copyop); //copy assignment operator
		
		std::map<std::string, float> map_;
		std::ifstream infile_;
		std::ifstream data_;
};

#endif