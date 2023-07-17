/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/07/17 17:46:37 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    vectime_ = 0;
    dequetime_ = 0;
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

PmergeMe::PmergeMe(char* ag[]) : input_(ag)
{
    std::cout << "Constructor with string" << std::endl;
    vectime_ = 0;
    dequetime_ = 0;
    straggler_ = -1;
}

void PmergeMe::CreateVectorPairs()
{
    int i = 1;
    while(input_[i] != NULL && input_[i + 1] != NULL)
    {
        int num = std::strtod(input_[i++], NULL);
        int num2 = std::strtod(input_[i], NULL);
        vecpairs_.push_back(std::make_pair(num, num2));
        i++;
    }
    if(input_[i] != NULL)
        straggler_ = std::strtod(input_[i], NULL);
}

void PmergeMe::SortInsidePairs()
{
    for(unsigned int i = 0; i < vecpairs_.size(); i++)
    {
        if(vecpairs_[i].first > vecpairs_[i].second)
            std::swap(vecpairs_[i].first, vecpairs_[i].second);
        
    }
}

void PmergeMe::SortOutsidePairsRecursively(std::vector<std::pair<int, int> >& pairs)
{
    if (pairs.size() <= 1) {
        return;
    }
    std::vector<std::pair<int, int> > sortedPairs;
    for (unsigned int i = 0; i < pairs.size(); i += 2) {
        if (i + 1 < pairs.size()) {
            std::pair<int, int> currentPair(pairs[i].second, pairs[i + 1].second);
            sortedPairs.push_back(currentPair);
        } else {
            sortedPairs.push_back(pairs[i]);
        }
    }
    pairs = sortedPairs;
    std::cout << "PAIRS RECURSION" << std::endl;
    for(unsigned int i = 0; i < pairs.size(); i++)
        std::cout << pairs[i].first << ", " << pairs[i].second << std::endl;       
    SortOutsidePairsRecursively(pairs);
}

void PmergeMe::MainProcess()
{
    CheckElements();
    // VECTOR
    // std::clock_t time = std::clock();

    CreateVectorPairs();
    SortInsidePairs();
    // PRINTING PAIRS
    for(unsigned int i = 0; i < vecpairs_.size(); i++)
        std::cout << vecpairs_[i].first << ", " << vecpairs_[i].second << std::endl;
    // PRINTING PAIRS
    // for(unsigned int i = 0; i < vecpairs_.size(); i++)
    //     std::cout << vecpairs_[i].first << ", " << vecpairs_[i].second << std::endl;    
    // sortVector(vec_);
    // std::clock_t endtime = std::clock();
    // vectime_ = 1000 * 1000 * (endtime - time) / (CLOCKS_PER_SEC); //mikroseconds µs
    // DEQUE
    // time = std::clock();
    // CheckAndStoreElements(deque_);
    // sortdeque(deque_);
    // endtime = std::clock();
    // dequetime_ = 1000 * 1000 * (endtime - time) / (CLOCKS_PER_SEC); //mikroseconds µs

    // // OUTPUT
    // std::cout << "Before:\t";
    // getContainerElements(vec_);
    // std::cout << PURPLE "After std::vector:\t" RESET;
    // getContainerElements(final_);
    // std::cout << BLUE "After std::deque:\t" RESET;
    // getContainerElements(finaldeque_);
    // std::cout << PURPLE "Time to process a range of " << final_.size()
    //     << " elements with std::vector : " RESET << vectime_ << " µs" << std::endl;
    // std::cout << BLUE "Time to process a range of "<< finaldeque_.size()
    //     << " elements with std::deque  : " RESET << dequetime_ << " µs" << std::endl;
}

void PmergeMe::sortVector(std::vector<int> a)
{
    if(a.size() <= 1)
    {
        final_ = a;
        return ;
    }
    final_ = MergeSort(vec_);
}

// Part vector in half until only 2 or in odd case 1 element left
std::vector<int> PmergeMe::MergeSort(std::vector<int> a)
{
    std::vector<int> tmp;

    if(a.size() <= 1)
        return (a);
    // std::cout << "VECTOR Merge Sort:" << std::endl;
    std::vector<int>left(a.begin(), a.begin() + a.size() / 2);
    std::vector<int>right(a.begin() + a.size() / 2, a.end());

    // getContainerElements(a);
    left = MergeSort(left);
    right = MergeSort(right);
    tmp = InsertionSort(left, right);
    return(tmp);
}

// sort two vectors in a final by combining them
std::vector<int> PmergeMe::InsertionSort(std::vector<int> res, std::vector<int> b)
{
    std::vector<int> newres;
    unsigned int j = 0;
    unsigned int i = 0;

    std::cout << "VECTOR Insertion Sort:" << std::endl;
    while (i < res.size() && j < b.size())
    {
        if(b[j] > res[i])
            newres.push_back(res[i++]);
        else
            newres.push_back(b[j++]);
    }
    // In case of different sizes of res & b -> rest would be missing
    while (i < res.size())
        newres.push_back(res[i++]);
    while (j < b.size())
        newres.push_back(b[j++]);
    // getContainerElements(newres);
    return(newres);
}

// LIST FUNCTIONS

void PmergeMe::sortdeque(std::deque<int> a)
{
    if(a.size() <= 1)
    {
        finaldeque_ = a;
        return ;
    }
    finaldeque_ = MergeSortdeque(deque_);
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
    // In case of different sizes of res & b -> rest would be missing
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

// EXCEPTIONS

const char* PmergeMe::InvalidElement::what() const throw()
{
	return("Error: check elements!");
}