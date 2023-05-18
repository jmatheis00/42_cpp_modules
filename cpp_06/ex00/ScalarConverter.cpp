/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/18 16:03:20 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	type_ = "Default";
	in_ = "Default";
	overflowflevel_ = 0;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copyclass)
{
	type_ = copyclass.type_;
	in_ = copyclass.in_;
	overflowflevel_ = 0;
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

void ScalarConverter::check_overflow(char* input)
{
	double d = strtod(input, NULL);
	if (d > std::numeric_limits<double>::max() ||
		d < std::numeric_limits<double>::min())
	{
		overflowflevel_ = 3;
		return ;
	}
	if (d > std::numeric_limits<float>::max() ||
		d < std::numeric_limits<float>::min())
	{
		overflowflevel_ = 2;
		return ;
	}
	if (d > std::numeric_limits<int>::max() ||
		d < std::numeric_limits<int>::min())
	{
		overflowflevel_ = 1;
		return ;
	}
}

void ScalarConverter::char_conversion(void)
{
	char c = static_cast<char>(in_[0]);
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
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

	if (std::isprint(static_cast<char>(start)))
		std::cout << "char: '" << static_cast<char>(start) << "'" << std::endl;
	else if (type_ == "SPECIAL")
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (type_ == "SPECIAL" || overflowflevel_ > 0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(start) << std::endl;

	std::cout.precision(1); //CHANGE NUMBER OF POSITIONS BEHIND POINT

	if (overflowflevel_ > 1 && type_ != "SPECIAL")
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << static_cast<float>(start) << "f" << std::endl;

	if (overflowflevel_ > 2 && type_ != "SPECIAL")
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed  << static_cast<double>(start) << std::endl;
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
	{
		check_overflow(input);
		staticcast_conversion(input);
	}
}
