/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/07/01 17:16:16 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    std::cout << "Default Constructor" << std::endl;
}

RPN::RPN(const RPN &copyclass)
{
    *this = copyclass;
}

RPN& RPN::operator= (const RPN& copyop)
{
    if (this != &copyop)
    {

    }
    return(*this);
}

RPN::~RPN()
{
    // std::cout << "Destructor" << std::endl;
}

RPN::RPN(std::string input) : s_(input)
{
    // std::cout << "Constructor with string" << std::endl;
}

bool RPN::CheckCharacters()
{
    for(unsigned int i = 0; i < s_.length(); i++)
    {
        if (std::isdigit(s_[i]) == false &&
            s_[i] != ' ' && s_[i] != '+' && s_[i] != '-'
            && s_[i] != '/' && s_[i] != '*')
            return(false);
    }
    return(true);
}

void RPN::Split()
{
    std::istringstream stream(s_);
    std::string token;

    while(stream >> token)
    {
        if (token == "-" || token == "+" || token == "/" || token == "*")
            calculate(token);
        else if (token.length() == 1 && strtod(token.c_str(), NULL) < 10 && strtod(token.c_str(), NULL) >= 0)
            stack_.push(strtod(token.c_str(), NULL));
        else
            throw TokenError();
    }
    std::cout << YELLOW "RESULT: " << stack_.top() << RESET << std::endl;
    stack_.pop();
    
}

// isOperator function?
void RPN::calculate(std::string t)
{
    if (stack_.size() < 2)
        throw CalculationError();
    else
    {
        int one = stack_.top();
        stack_.pop();
        int two = stack_.top();
        stack_.pop();
        int result = 0;
        if (t == "-")
            result = two - one;
        else if (t == "+")
            result = two + one;
        else if (t == "*")
            result = two * one;
        else if (t == "/")
            result = two / one;
        stack_.push(result);
    }
}

// EXCEPTIONS

const char* RPN::TokenError::what() const throw()
{
	return("Error: Invalid token, check string!");
}

const char* RPN::CalculationError::what() const throw()
{
	return("Error: Calculation not possible, invalid string!");
}