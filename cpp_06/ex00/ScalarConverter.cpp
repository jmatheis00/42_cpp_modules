/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/24 09:53:22 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	// std::cout << "Constructor" << std::endl;
	type_ = "Default";
	in_ = "Default";
	c_ = 0;
	i_ = 0;
	f_ = 0;
	d_ = 0;
	li_ = 0;
	ld_ = 0;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copyclass)
{
	// std::cout << "Copy Constructor" << std::endl;
	*this = copyclass;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& copyop)
{
	// std::cout << "Copy Assignment Operator" << std::endl;
	if (this != &copyop)
	{
		type_ = copyop.type_;
		in_ = copyop.in_;
		c_ = copyop.c_;
		i_ = copyop.i_;
		f_ = copyop.f_;
		d_ = copyop.d_;
		li_ = copyop.d_;
		ld_ = copyop.ld_;
	}
	return(*this);
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << "Destructor" << std::endl;
}

// OTHER MEMBER FUNCTIONS

// Check for nonnumeric, max. 1 point, max 1 f at the end
int ScalarConverter::check_for_error()
{
	int pointcount = 0;
	int length = (int)in_.length() - 1;

	if (in_ == "nan" || in_ == "nanf" || in_ == "+inf"
		|| in_ == "+inff" || in_ == "-inf" || in_ == "-inff"
		|| (in_.length() == 1 && std::isprint(in_[0])))
		return(0);
	if ((std::isdigit(in_[0]) == false && in_[0] != '.' && in_[0] != '-')
		|| in_ == "-f")
		return(1);
	for (int i = 1; i < length; i++)
	{
		if (std::isdigit(in_[i]) == false && in_[i] != '.')
			return(1);
		if (in_[i] == '.')
			pointcount++;
	}
	if (pointcount > 1 || (std::isdigit(in_[length]) == false
			&& in_[length] != '.' && in_[length] != 'f'))
		return(1);
	return(0);
}

// FIND TYPE (CHAR, INT, FLOAT, DOUBLE)
void ScalarConverter::check_for_type(void)
{
	if(in_.length() == 1 && std::isprint(in_[0]))
		type_ = "CHAR";
	if ((in_[in_.length() - 1] == 'f' && in_.length() != 1)
		|| in_ == "-inff" || in_ == "+inff" || in_ == "nanf")
		type_ = "FLOAT";
	else if (in_.find(".") != std::string::npos
		|| in_ == "-inf" || in_ == "+inf" || in_ == "nan")
		type_ = "DOUBLE";
	else if (strtod(in_.c_str(), NULL) != 0 || in_ == "0")
		type_ = "INT";
	check_overflows();
}

// IF INT OVERFLOWS -> MUST BE FLOAT, IF FLOAT OVERFLOW -> DOUBLE
void ScalarConverter::check_overflows(void)
{
	double test = strtod(in_.c_str(), NULL);
	if (type_ == "INT" && (test > std::numeric_limits<int>::max() ||
		test < std::numeric_limits<int>::min()))
		type_ = "FLOAT";
	if (type_ == "FLOAT" && (test > std::numeric_limits<float>::max() ||
		test < std::numeric_limits<float>::min()))
		type_ = "DOUBLE";
}

// CONVERT FROM ORIGINAL TYPE TO OTHER TYPES

void ScalarConverter::char_conversion(void)
{
	c_ = static_cast<char>(in_[0]);
	i_ = static_cast<int>(c_);
	f_ = static_cast<float>(c_);
	d_ = static_cast<double>(c_);
	li_ = static_cast<long int>(c_);
	ld_ = static_cast<long double>(c_);
}

void ScalarConverter::int_conversion(void)
{
	i_ = static_cast<int>(strtod(in_.c_str(), NULL));
	li_ = static_cast<long int>(strtol(in_.c_str(), NULL, 0));
	c_ = static_cast<char>(i_);
	f_ = static_cast<float>(i_);
	d_ = static_cast<double>(i_);
	ld_ = static_cast<long double>(i_);
}

void ScalarConverter::float_conversion(void)
{
	f_ = static_cast<float>(strtod(in_.c_str(), NULL));
	c_ = static_cast<char>(f_);
	i_ = static_cast<int>(f_);
	d_ = static_cast<double>(f_);
	li_ = static_cast<long int>(f_);
	ld_ = static_cast<long double>(f_);	
}

void ScalarConverter::double_conversion(void)
{
	d_ = static_cast<double>(strtod(in_.c_str(), NULL));
	ld_ = static_cast<long double>(d_);	
	c_ = static_cast<char>(d_);
	i_ = static_cast<int>(d_);
	f_ = static_cast<float>(d_);
	li_ = static_cast<long int>(d_);
}

// PRINTING FUNCTIONS FOR EVERY TYPE

// printable chars : 32 - 126
void ScalarConverter::print_char(void)
{
	std::cout << RED "char: " RESET;
	if (std::isprint(c_) && d_ < 127 && d_ > 31)
		std::cout << "\'" << c_ << "\'" << std::endl;
	else if(f_ == -std::numeric_limits<float>::infinity() ||
		f_ == std::numeric_limits<float>::infinity() ||
		d_ == -std::numeric_limits<double>::infinity() ||
		d_ == std::numeric_limits<double>::infinity() ||
		in_ == "nanf" || in_ == "nan")
		std::cout << "impossible" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::print_int(void)
{
	std::cout << RED "int: " RESET;
	if ((li_ > std::numeric_limits<int>::max() ||
		li_ < std::numeric_limits<int>::min()) ||
		f_ == -std::numeric_limits<float>::infinity() ||
		f_ == std::numeric_limits<float>::infinity() ||
		d_ == -std::numeric_limits<double>::infinity() ||
		d_ == std::numeric_limits<double>::infinity() ||
		in_ == "nanf" || in_ == "nan")
		std::cout << "impossible" << std::endl;
	else
		std::cout << i_ << std::endl;
}

void ScalarConverter::print_float(void)
{
	std::cout << RED "float: " RESET;
	if (f_ == -std::numeric_limits<float>::infinity())
		std::cout << "-inff" << std::endl;
	else if (f_ == std::numeric_limits<float>::infinity())
		std::cout << "+inff" << std::endl;
	else if (d_ > std::numeric_limits<float>::max() ||
		d_ < -std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else if (in_ == "nanf" || in_ == "nan")
		std::cout << "nanf" << std::endl;
	else
	{
		std::cout << std::setprecision(1) << std::fixed
			<< f_ << "f" << std::endl;
	}
}

void ScalarConverter::print_double(void)
{
	std::cout << RED "double: " RESET;
	if (d_ == -std::numeric_limits<double>::infinity())
		std::cout << "-inf" << std::endl;
	else if (d_ == std::numeric_limits<double>::infinity())
		std::cout << "+inf" << std::endl;
	else if (ld_ > std::numeric_limits<double>::max() ||
		ld_ < -std::numeric_limits<double>::max())
		std::cout << "impossible" << std::endl;
	else if (in_ == "nanf" || in_ == "nan")
		std::cout << "nan" << std::endl;
	else
	{
		std::cout << std::setprecision(1) << std::fixed
			<< d_ << std::endl;
	}
}

// CONVERTING INPUT TO THE FOUR TYPES & PRINTING THEM
void ScalarConverter::convert(char* input)
{
	in_ = (std::string)input;
	if (check_for_error() == 1)
	{
		std::cout << "Input is invalid, try again" << std::endl;		
		exit(EXIT_FAILURE);
	}		
	check_for_type();
	if (type_ == "Default")
	{
		std::cout << "Input is invalid, try again" << std::endl;		
		exit(EXIT_FAILURE);
	}
	if (type_ == "CHAR")
		char_conversion();
	if (type_ == "INT")
		int_conversion();
	if (type_ == "FLOAT")
		float_conversion();
	if (type_ == "DOUBLE")
		double_conversion();
	print_char();
	print_int();
	print_float();
	print_double();
}
