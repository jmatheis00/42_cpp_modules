/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/20 13:06:58 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << "Default Constructor" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copyclass)
{
    *this = copyclass;
}

PmergeMe& PmergeMe::operator= (const PmergeMe& copyop)
{
    if (this != &copyop)
    {

    }
    return(*this);
}

PmergeMe::~PmergeMe()
{
    std::cout << "Destructor" << std::endl;
}

PmergeMe::PmergeMe(char* ag[])
{
    std::cout << "Constructor with string" << std::endl;

    for(int i = 1; ag[i] != NULL; i++)
    {
        int num = std::atoi(ag[i]);
        vec_.push_back(num);
        deque_.push_back(num);
    }
    std::cout << "Before:\t";
    getContainerElements(vec_);
    sortVector(vec_);
    sortdeque(deque_);
    // getContainerElements(deque);

//    getTokens(ag);
}

void PmergeMe::sortVector(std::vector<int> a)
{
    std::clock_t time = std::clock();

    // get first and second
    std::vector<int> first;
    std::vector<int> second;
    if(a.size() <= 1)
    {
        final_ = a;
        return ;
    }
    std::vector<int>::iterator it = a.begin();
    for(unsigned int i = 0; i <= a.size()/2; i++)
    {
        first.push_back(*it);
        a.erase(it);
    }
    second = a;

    vecleft_ = MergeSort(first);
    vecright_ = MergeSort(second);

    final_ = InsertionSort(vecleft_, vecright_);

    std::cout << "After:\t";
    for(unsigned int i = 0; i < final_.size(); i++)
        std::cout << final_[i] << " ";
    std::cout << std::endl;

    std::clock_t endtime = std::clock();
    double sortedtime = 1000 * 1000 * (endtime - time) / (CLOCKS_PER_SEC); //mikroseconds µs
    std::cout << "Time to process a range of " << final_.size()
        << " elements with std::vector : " << sortedtime << " µs" << std::endl;
}


std::vector<int> PmergeMe::MergeSort(std::vector<int> a)
{
    std::vector<int> tmp;
    if(a.size() <= 1)
        return (a);
    
    std::vector<int>left(a.begin(), a.begin() + a.size() / 2);
    std::vector<int>right(a.begin() + a.size() / 2, a.end());

    left = MergeSort(left);
    right = MergeSort(right);
    tmp = InsertionSort(left, right);

    return(tmp);
}

std::vector<int> PmergeMe::InsertionSort(std::vector<int> res, std::vector<int> b)
{
    std::vector<int> newres;
    unsigned int j = 0;
    unsigned int i = 0;

    while (i < res.size() && j < b.size())
    {
        if(b[j] > res[i])
            newres.push_back(res[i++]);
        else
            newres.push_back(b[j++]);
    }
    // Füge die restlichen Elemente von res bzw. bhinzu, falls vorhanden
    while (i < res.size())
        newres.push_back(res[i++]);
    while (j < b.size())
        newres.push_back(b[j++]);
    return(newres);
}

// LIST FUNCTIONS

void PmergeMe::sortdeque(std::deque<int> a)
{
    std::clock_t time = std::clock();

    // get first and second
    std::deque<int> first;
    std::deque<int> second;
    if(a.size() <= 1)
    {
        finaldeque_ = a;
        return ;
    }
    std::deque<int>::iterator it = a.begin();
    for(unsigned int i = 0; i <= a.size()/2; i++)
    {
        first.push_back(*it);
        a.erase(it);
    }
    second = a;

    dequeleft_ = MergeSortdeque(first);
    dequeright_ = MergeSortdeque(second);

    finaldeque_ = InsertionSortdeque(dequeleft_, dequeright_);

    std::clock_t endtime = std::clock();
    double sortedtime = 1000 * 1000 * (endtime - time) / (CLOCKS_PER_SEC); //mikroseconds µs
    std::cout << "Time to process a range of " << finaldeque_.size()
        << " elements with std::deque  : " << sortedtime << " µs" << std::endl;
}

std::deque<int> PmergeMe::MergeSortdeque(std::deque<int> a)
{
    std::deque<int> tmp;
    if(a.size() <= 1)
        return (a);
    
    std::deque<int>::iterator it = a.begin();
    std::deque<int>left;
    std::deque<int>right;

    for(unsigned int i = 0; i < a.size()/2; i++)
    {
        left.push_back(*it);
        it++;
    }
    for(unsigned int i = a.size()/2; i < a.size(); i++)
    {
        right.push_back(*it);
        it++;
    }

    left = MergeSortdeque(left);
    right = MergeSortdeque(right);
    tmp = InsertionSortdeque(left, right);

    return(tmp);
}

std::deque<int> PmergeMe::InsertionSortdeque(std::deque<int> res, std::deque<int> b)
{
    std::deque<int> newres;

    std::deque<int>::iterator itres = res.begin();
    std::deque<int>::iterator itb = b.begin();

    while (itres != res.end() && itb != b.end())
    {
        if(*itb > *itres)
        {
            newres.push_back(*itres);
            itres++;
        }
        else
        {
            newres.push_back(*itb);
            itb++;
        }
    }
    // Füge die restlichen Elemente von res bzw. bhinzu, falls vorhanden
    while (itres != res.end())
    {
        newres.push_back(*itres);
        itres++;
    }
    while (itb != b.end())
    {
        newres.push_back(*itb);
        itb++;
    }
    return(newres);
}