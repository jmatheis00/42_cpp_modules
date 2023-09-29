/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:23:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:35:14 by jmatheis         ###   ########.fr       */
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

Span &Span::operator=(const Span &copyop)
{
    std::cout << "Copy Assignment Operator" << std::endl;
    if (this != &copyop)
    {
        N_ = copyop.N_;
        vec_ = copyop.vec_;
    }
    return (*this);
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

    unsigned int smallestspan = static_cast<unsigned int>(std::abs(itb[0] - itb[1]));
    itb++;
    while (itb < ite - 1)
    {
        int tmp = *itb;
        itb++;
        if (smallestspan > static_cast<unsigned int>(std::abs(*itb - tmp)))
            smallestspan = std::abs(*itb - tmp);
    }
    return (smallestspan);
}

unsigned int Span::longestSpan()
{
    if (vec_.size() < 2)
        throw NoSpanFound();
    std::vector<int>::iterator min = std::min_element(vec_.begin(), vec_.end());
    std::vector<int>::iterator max = std::max_element(vec_.begin(), vec_.end());

    return (static_cast<unsigned int>(std::abs(*max - *min)));
}

void Span::addmanyNumbers(std::vector<int> range) // Parameter: vector or similar
{
    if (N_ - vec_.size() < range.size())
        throw SpanIsAlreadyFilled();

    std::vector<int>::iterator rb = range.begin();
    std::vector<int>::iterator re = range.end();

    vec_.insert(vec_.end(), rb, re);
}

void Span::addmanyNumbers(std::vector<int>::iterator itb, std::vector<int>::iterator ite)
{
    unsigned int range = 0;
    for (std::vector<int>::iterator tmp = itb; tmp < ite; tmp++)
        range++;

    if (N_ - vec_.size() < range)
        throw SpanIsAlreadyFilled();
    vec_.insert(vec_.end(), itb, ite);
}

// GET SPAN
void Span::getSpan()
{
    std::vector<int>::iterator beg = vec_.begin();
    std::cout << PURPLE "SPAN PRINTED" RESET << std::endl;
    while (beg != vec_.end())
    {
        std::cout << *beg << "\t";
        beg++;
    }
    std::cout << std::endl;
}

int Span::getSize()
{
    return (vec_.size());
}

// EXCEPTIONS
const char *Span::SpanIsAlreadyFilled::what() const throw()
{
    return ("Span is already completely filled!");
}

const char *Span::NoSpanFound::what() const throw()
{
    return ("Could not found a Span!");
}
