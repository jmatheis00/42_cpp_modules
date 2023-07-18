/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/07/18 17:07:29 by jmatheis         ###   ########.fr       */
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
        if(vecpairs_[i].first < vecpairs_[i].second)
            std::swap(vecpairs_[i].first, vecpairs_[i].second);
        
    }
}

std::vector<std::pair<int, int> >PmergeMe::MergeSort_SortPairs(std::vector<std::pair<int, int> > pairs)
{
    std::vector<std::pair<int, int> >tmp;

    if(pairs.size() <= 1)
        return (pairs);
    std::vector<std::pair<int, int> >left(pairs.begin(), pairs.begin() + pairs.size() / 2);
    std::vector<std::pair<int, int> >right(pairs.begin() + pairs.size() / 2, pairs.end());

    left = MergeSort_SortPairs(left);
    right = MergeSort_SortPairs(right);
    tmp = InsertionSort_SortPairs(left, right);
    return(tmp);
}

std::vector<std::pair<int, int> >PmergeMe::InsertionSort_SortPairs(std::vector<std::pair<int, int> >res, std::vector<std::pair<int, int> >b)
{
    std::vector<std::pair<int, int> > newres;
    unsigned int j = 0;
    unsigned int i = 0;

    while (i < res.size() && j < b.size())
    {
        if(b[j].first > res[i].first)
            newres.push_back(res[i++]);
        else
            newres.push_back(b[j++]);
    }
    while (i < res.size())
        newres.push_back(res[i++]);
    while (j < b.size())
        newres.push_back(b[j++]);
    return(newres);
}

void PmergeMe::CreateMainAndPendChain()
{
    main_.push_back(vecpairssorted_[0].second);
    for(unsigned int i = 0; i < vecpairssorted_.size(); i++)
        main_.push_back(vecpairssorted_[i].first);
    for(unsigned int i = 1; i < vecpairssorted_.size(); i++)
        pend_.push_back(vecpairssorted_[i].second);    
}

int PmergeMe::Jacobstahl(int index)
{
    if (index == 0)
        return (0);
    if (index == 1)
        return(1);
    int jacobs;
    int first = 0;
    int second = 1;
    for (int i = 2; i <= index; i++)
    {
        jacobs = second + 2 * first;
        first = second;
        second = jacobs;
    }
    return(jacobs);
}

int PmergeMe::CombinedSequence(int index)
{
    std::vector<int> sequence;
    sequence.push_back(3);  // Startwert der Jacobsthal-Zahlen
    sequence.push_back(2);  // Startwert der Indexe

    int jacobs[2] = {3, 2};  // Aktuelle Jacobsthal-Zahl und Index
    int nextIndex = 2;

    while (nextIndex <= index)
    {
        int diff = jacobs[0] - jacobs[1];

        if (diff > 1)
        {
            for (int i = jacobs[0] - 1; i > jacobs[1]; i--)
            {
                sequence.push_back(i);
                sequence.push_back(i - 1);
                nextIndex += 2;
                if (nextIndex > index)
                    break;
            }
        }

        jacobs[0] = jacobs[0] + 2 * jacobs[1];
        jacobs[1]++;
        
        sequence.push_back(jacobs[0]);
        sequence.push_back(jacobs[1]);
        nextIndex += 2;
    }

    return sequence[index * 2 - 1];
}

void PmergeMe::InsertPend()
{
    int j = Jacobstahl(8);
    // std::cout << "COMBINED: " << s << std::endl;
    for(int i = 0; i < 10; i++)
    {
        std::cout << CombinedSequence(i) << std::endl;
    }
    // int s = CombinedSequence(7);
    std::cout << "JACOBS: " << std::endl;
    std::cout << j << std::endl;
}

int PmergeMe::BinarySearch(int start, int end, int val)
{
    int middle = start + (end - start) / 2;
    if(main_[middle] == val
        || (main_[middle] > val && middle - 1 < 0)
        || (main_[middle] > val && middle - 1 >= 0 && main_[middle - 1] < val )
        || (main_[middle] < val && middle + 1 > end)
        || (main_[middle] < val && middle + 1 <= end && main_[middle + 1] > val ))
            return (middle);
    if(main_[middle] > val)
        return (BinarySearch(start, middle - 1, val));
    if(main_[middle] < val)
        return (BinarySearch(middle + 1, end, val));
    return(-1);
}

void PmergeMe::MainProcess()
{
    CheckElements();
    // VECTOR
    // std::clock_t time = std::clock();

    CreateVectorPairs();
    SortInsidePairs();
    if(vecpairs_.size() <= 1)
    {
        vecpairssorted_ = vecpairs_;
        return ;
    }
    vecpairssorted_ = MergeSort_SortPairs(vecpairs_);
    // PRINTING PAIRS
    // for(unsigned int i = 0; i < vecpairssorted_.size(); i++)
    //     std::cout << vecpairssorted_[i].first << ", " << vecpairssorted_[i].second << std::endl;
    // CREATE MAIN CHAIN AND PEND CHAIN
    CreateMainAndPendChain();
    std::cout << "MAIN" << std::endl;
    getContainerElements(main_);
    std::cout << "PEND" << std::endl;
    getContainerElements(pend_);
    InsertPend();
    
    // int pos = BinarySearch(0, main_.size(), pend_[2]);
    // if (pos == -1)
    // {
    //     std::cout << "POS: " << pos << std::endl;
    //     exit(1);
    // }
    // std::vector<int>::iterator it = main_.begin() + pos;
    // main_.insert(it, pend_[2]);
    // if (straggler_ != -1)
    //     pos = BinarySearch(0, main_.size(), straggler_);
    // std::cout << "POS: " << pos << std::endl;
    // it = main_.begin() + pos;
    // main_.insert(it, straggler_);
    // std::cout << "after binary" << std::endl;
    // getContainerElements(main_);
    

}


// EXCEPTIONS
const char* PmergeMe::InvalidElement::what() const throw()
{
	return("Error: check elements!");
}