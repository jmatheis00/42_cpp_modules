/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/18 14:42:39 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	type_ = "Default";
	in_ = "Default";
}

ScalarConverter::ScalarConverter(const ScalarConverter &copyclass)
{
	type_ = copyclass.type_;
	in_ = copyclass.in_;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& copyop)
{
	if (this != &copyop)
	{
		type_ = copyop.type_;
		in_ = copyop.in_;
	}
	return(*this);
}

ScalarConverter::~ScalarConverter()
{
	
}

// OTHER MEMBER FUNCTIONS

void ScalarConverter::check_for_type(char* input)
{
	if(in_.length() == 1 && std::isprint(in_[0]))
		type_ = "CHAR";
	if (in_ == "-inff" || in_ == "+inff" || in_ == "nanf"
		|| in_ == "-inf" || in_ == "+inf" || in_ == "nan"
		|| (in_.length() == 1 && in_[0] == '0'))
		type_ = "SPECIAL";
	if (in_[in_.length() - 1] == 'f' && in_.find(".") != std::string::npos
		&& in_.find(".", in_.find(".") + 1) == std::string::npos)
		type_ = "FLOAT";
	else if (in_.find(".") != std::string::npos
		&& in_.find(".", in_.find(".") + 1) == std::string::npos)
		type_ = "DOUBLE";
	else if (atoi(input) != 0)
		type_ = "INT";
}

void ScalarConverter::char_conversion(void)
{
	char c = static_cast<char>(in_[0]);
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout.precision(1); //CHANGE NUMBER OF POSITIONS BEHIND POINT
	std::cout << "float: " << std::fixed
		<< static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed
		<< static_cast<double>(c) << std::endl;	
}

void ScalarConverter::staticcast_conversion(char* input)
{
	double start = atof(input);

	char c = static_cast<char>(start);

	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else if (type_ == "SPECIAL")
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	int i = static_cast<int>(start);
	if (type_ == "SPECIAL" || (start > INT_MAX || start < INT_MIN))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	std::cout.precision(1); //CHANGE NUMBER OF POSITIONS BEHIND POINT

	float f = static_cast<float>(start);
	if ((start > __FLT_MAX__ || start < __FLT_MIN__) && type_ != "SPECIAL")
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << f << "f" << std::endl;
	double d = static_cast<double>(start);
	if ((start > __DBL_MAX__ || start < __DBL_MIN__) && type_ != "SPECIAL")
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed  << d << std::endl;
}

void ScalarConverter::convert(char* input)
{
	in_ = (std::string)input;
	check_for_type(input);
	if (type_ == "Default")
	{
		std::cout << "Input is invalid, try again" << std::endl;		
		exit(EXIT_FAILURE);
	}
	if (type_ == "CHAR")
		char_conversion();
	else
		staticcast_conversion(input);
}
