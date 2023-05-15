/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/15 15:01:30 by jmatheis         ###   ########.fr       */
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
	else if (in_ == "-inff" || in_ == "+inff" || in_ == "nanf"
		|| in_ == "-inf" || in_ == "+inf" || in_ == "nan")
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

// void ScalarConverter::check_for_special()
// {

// }

// void ScalarConverter::check_for_numbertype(char* input)
// {
// 	if (in_[in_.length() - 1] == 'f' && in_.find(".") != std::string::npos
// 		&& in_.find(".", in_.find(".") + 1) == std::string::npos)
// 		type_ = "FLOAT";
// 	else if (in_.find(".") != std::string::npos
// 		&& in_.find(".", in_.find(".") + 1) == std::string::npos)
// 		type_ = "DOUBLE";
// 	else if (atoi(input) != 0)
// 		type_ = "INT";
// }

#include <iomanip>

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
	if (type_ == "SPECIAL")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	float f = static_cast<float>(start);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	double d = static_cast<double>(start);
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(char* input)
{
	in_ = (std::string)input;
	check_for_type(input);
	if (type_ == "Default")
	{
		std::cout << "Input is just a string, nothing else" << std::endl;		
		exit(1);
	}
	int_conversion(input);
}
