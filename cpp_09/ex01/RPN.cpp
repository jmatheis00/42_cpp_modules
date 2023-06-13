/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/13 13:17:31 by jmatheis         ###   ########.fr       */
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
    std::cout << "Destructor" << std::endl;
}

RPN::RPN(std::string input)
{
    std::cout << "Constructor with string" << std::endl;
    s_ = input;
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
        std::cout << i << std::endl;
    }
    
}

void RPN::calculate(std::string t)
{
    if (stack_.size() < 2)
        std::cout << "Calculation not possible, invalid string" << std::endl;
    else
    {
        if (t == "-")
            stack_[0] - stack[1];
        else if (t == "+")
            stack_[0] - stack[1];
    }
}