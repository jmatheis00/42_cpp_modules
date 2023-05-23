/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/23 13:15:47 by jmatheis         ###   ########.fr       */
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

		int check_for_error(void);
		void check_for_type(void);
		void check_overflows(void);
		
		void convert(char* input);

		void char_conversion(void);
		void int_conversion(void);
		void float_conversion(void);
		void double_conversion(void);
		
		void print_char(void);
		void print_int(void);
		void print_float(void);
		void print_double(void);

	private:
		std::string type_;
		std::string in_;

		char c_;
		int	i_;
		float f_;
		double d_;
		long int li_;
		long double ld_;
};

#endif