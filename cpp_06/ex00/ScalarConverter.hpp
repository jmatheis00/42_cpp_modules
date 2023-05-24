/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/24 12:29:15 by jmatheis         ###   ########.fr       */
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
		static int check_for_error(void);
		static void check_for_type(void);
		static void check_overflows(void);
		
		static void convert(char* input);

		static void char_conversion(void);
		static void int_conversion(void);
		static void float_conversion(void);
		static void double_conversion(void);
		
		static void print_char(void);
		static void print_int(void);
		static void print_float(void);
		static void print_double(void);

	private:
		ScalarConverter(); //Default Constructor
		ScalarConverter(const ScalarConverter &copyclass); //Copy Constructor
		ScalarConverter& operator= (const ScalarConverter& copyop); //copy assignment operator
		~ScalarConverter(); //Destructor

		static std::string type_;
		static std::string in_;

		static char c_;
		static int	i_;
		static float f_;
		static double d_;
		static long int li_;
		static long double ld_;
};

#endif