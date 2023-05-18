/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/18 15:59:22 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <numeric>
# include <cmath>
# include <iomanip>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

class ScalarConverter
{
    public:
		ScalarConverter(); //Default Constructor
		ScalarConverter(const ScalarConverter &copyclass); //Copy Constructor
		ScalarConverter& operator= (const ScalarConverter& copyop); //copy assignment operator
		~ScalarConverter(); //Destructor


		void check_for_type(char* input);
		void check_overflow(char* input);
		
		void convert(char* input);

		void staticcast_conversion(char* input);
		void char_conversion(void);

	private:
		std::string type_;
		std::string in_;
		int overflowflevel_;
		// 1: int
		// 2: float
		// 3: double
};

#endif