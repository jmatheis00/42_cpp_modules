/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/22 11:56:26 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
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
	type_ = copyclass.type_;
	in_ = copyclass.in_;
	c_ = copyclass.c_;
	i_ = copyclass.i_;
	f_ = copyclass.f_;
	d_ = copyclass.d_;
	li_ = copyclass.d_;
	ld_ = copyclass.ld_;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& copyop)
{
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
	
}

// OTHER MEMBER FUNCTIONS

void ScalarConverter::check_for_type(char* input)
{
	if(in_.length() == 1 && std::isprint(in_[0]))
		type_ = "CHAR";
	if ((in_[in_.length() - 1] == 'f' && in_.find(".") != std::string::npos
		&& in_.find(".", in_.find(".") + 1) == std::string::npos)
		|| in_ == "-inff" || in_ == "+inff" || in_ == "nanf")
		type_ = "FLOAT";
	else if ((in_.find(".") != std::string::npos
		&& in_.find(".", in_.find(".") + 1) == std::string::npos)
		|| in_ == "-inf" || in_ == "+inf" || in_ == "nan")
		type_ = "DOUBLE";
	else if (atoi(input) != 0 || (in_.length() == 1 && in_[0] == '0'))
		type_ = "INT";
}

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
	i_ = static_cast<int>(atoi(in_.c_str()));
	li_ = static_cast<long int>(strtol(in_.c_str(), NULL, 0));
	c_ = static_cast<char>(i_);
	f_ = static_cast<float>(i_);
	d_ = static_cast<double>(i_);
	ld_ = static_cast<long double>(i_);
}

void ScalarConverter::float_conversion(void)
{
	f_ = static_cast<float>(strtof(in_.c_str(), NULL));
	c_ = static_cast<char>(f_);
	i_ = static_cast<int>(f_);
	d_ = static_cast<double>(f_);
	li_ = static_cast<long int>(f_);
	ld_ = static_cast<long double>(f_);	
}

void ScalarConverter::double_conversion(void)
{
	d_ = static_cast<double>(strtod(in_.c_str(), NULL));
	ld_ = static_cast<long double>(strtold(in_.c_str(), NULL));	
	c_ = static_cast<char>(d_);
	i_ = static_cast<int>(d_);
	f_ = static_cast<float>(d_);
	li_ = static_cast<long int>(d_);
}

void ScalarConverter::print_char(void)
{
	std::cout << "char: ";
	if (std::isprint(c_))
		std::cout << "\'" << c_ << "\'" << std::endl;
	else if(std::isinf(f_) || std::isinf(d_) || std::isnan(f_) || std::isnan(d_))
		std::cout << "impossible" << std::endl;
	else
		std::cout << "non displayable" << std::endl;
}

void ScalarConverter::print_int(void)
{
	std::cout << "int: ";
	if (li_ > std::numeric_limits<int>::max() ||
		li_ < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << i_ << std::endl;
}

void ScalarConverter::print_float(void)
{
	std::cout << "float: ";
	if (std::isinf(f_) == true && d_ < std::numeric_limits<float>::min())
		std::cout << "-inff" << std::endl;
	else if (std::isinf(f_) == true && d_ > std::numeric_limits<float>::max())
		std::cout << "+inff" << std::endl;
	else if ((d_ > std::numeric_limits<float>::max() ||
		d_ < std::numeric_limits<float>::min()) && f_ != 0)
		std::cout << "impossible" << std::endl;
	else if (std::isnan(f_) == true)
		std::cout << "nanf" << std::endl;
	else
	{
		std::cout.precision(1);
		std::cout << std::fixed << f_ << "f" << std::endl;
	}
}

void ScalarConverter::print_double(void)
{
	std::cout << "double: ";
	if (std::isinf(d_) == true && ld_ < std::numeric_limits<double>::min())
		std::cout << "-inf" << std::endl;
	else if (std::isinf(d_) == true && ld_ > std::numeric_limits<double>::max())
		std::cout << "+inf" << std::endl;
	else if ((ld_ > std::numeric_limits<double>::max() ||
		ld_ < std::numeric_limits<double>::min()) && d_ != 0)
		std::cout << "impossible" << std::endl;
	else if (std::isnan(d_) == true)
		std::cout << "nan" << std::endl;
	else
	{
		std::cout.precision(1);
		std::cout << std::fixed << d_ << std::endl;
	}
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
	if (type_ == "INT")
		int_conversion();
	if (type_ == "FLOAT")
		float_conversion();
	if (type_ == "DOUBLE")
		double_conversion();
	// std::cout << RED "INT: " << i_ << "\nFLOAT: " << f_ << "\nDOUBLE: " << d_ << RESET << std::endl;
	print_char();
	print_int();
	print_float();
	print_double();
	
}
