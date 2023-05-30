/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:23:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/30 18:38:39 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N_(0)
{
    std::cout << "Default Constructor" << std::endl;
}

Span::Span(unsigned int N) : N_(N)
{
    std::cout << "Constructor with Span size" << std::endl;
}

Span::Span(const Span &copyclass)
{
    std::cout << "Copy Constructor" << std::endl;
    *this = copyclass;
}

Span& Span::operator= (const Span& copyop)
{
    std::cout << "Copy Assignment Operator" << std::endl;
    if(this != &copyop)
    {

    }
    return(*this);
}

Span::~Span()
{
    std::cout << "Destructor" << std::endl;
}

// OTHER
void Span::addNumber(int i)
{
    if (vec_.size() != N_)
        vec_.push_back(i);
    else
        throw SpanIsAlreadyFilled();
}

unsigned int Span::shortestSpan()
{
    if (vec_.size() < 2)
        throw NoSpanFound();
    std::vector<int>::iterator itb = vec_.begin();
    std::vector<int>::iterator ite = vec_.end();
    std::sort(itb, ite);

    unsigned int smallestspan = static_cast <unsigned int> (std::abs(itb[0] - itb[1]));
    itb++;
    while(itb < ite - 1)
    {
        int tmp = *itb;
        itb++;
        if (smallestspan > static_cast <unsigned int> (std::abs(*itb - tmp)))
            smallestspan = std::abs(*itb - tmp);
    }
    return(smallestspan);
}

unsigned int Span::longestSpan()
{
    if (vec_.size() < 2)
        throw NoSpanFound();
    std::vector<int>::iterator min = std::min_element(vec_.begin(), vec_.end());
    std::vector<int>::iterator max = std::max_element(vec_.begin(), vec_.end());

    return(static_cast <unsigned int> (std::abs(*max - *min)));
}

void Span::addmanyNumber(std::vector<int> range) //Parameter: vector or similar
{
    if (N_ - vec_.size() < range.size())
        throw SpanIsAlreadyFilled();

    std::vector<int>::iterator rb = range.begin();
    std::vector<int>::iterator re = range.end();

    vec_.insert(vec_.end(), rb, re); //re + 1?
}

// GET SPAN
void Span::getSpan()
{
    std::vector<int>::iterator beg = vec_.begin();
    std::vector<int>::iterator end = vec_.end();
    std::cout << RED "SPAN" RESET << std::endl;
    while (beg < end)
    {
        std::cout << *beg << "\t";
        beg++;
    }
    std::cout << std::endl;
}

// EXCEPTIONS
const char* Span::SpanIsAlreadyFilled::what() const throw()
{
    return("Span is already completely filled!");
}

const char* Span::NoSpanFound::what() const throw()
{
    return("Could not found a Span!");
}
