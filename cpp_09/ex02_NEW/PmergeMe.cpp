/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/07/19 16:53:46 by jmatheis         ###   ########.fr       */
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
    Vstraggler_ = -1;
    Dstraggler_ = -1;
}

//  VECTOR FUNTIONS

void PmergeMe::V_CreatePairs()
{
    int i = 1;
    while(input_[i] != NULL && input_[i + 1] != NULL)
    {
        int num = std::strtod(input_[i++], NULL);
        int num2 = std::strtod(input_[i], NULL);
        Vpairs_.push_back(std::make_pair(num, num2));
        i++;
    }
    if(input_[i] != NULL)
        Vstraggler_ = std::strtod(input_[i], NULL);
}

void PmergeMe::V_SortInsidePairs()
{
    for(unsigned int i = 0; i < Vpairs_.size(); i++)
    {
        if(Vpairs_[i].first < Vpairs_[i].second)
            std::swap(Vpairs_[i].first, Vpairs_[i].second); 
    }
}

std::vector<std::pair<int, int> >PmergeMe::V_MergeSort_SortPairs(std::vector<std::pair<int, int> > pairs)
{
    std::vector<std::pair<int, int> >tmp;

    if(pairs.size() <= 1)
        return (pairs);
    std::vector<std::pair<int, int> >left(pairs.begin(), pairs.begin() + pairs.size() / 2);
    std::vector<std::pair<int, int> >right(pairs.begin() + pairs.size() / 2, pairs.end());

    left = V_MergeSort_SortPairs(left);
    right = V_MergeSort_SortPairs(right);
    tmp = V_InsertionSort_SortPairs(left, right);
    return(tmp);
}

std::vector<std::pair<int, int> >PmergeMe::V_InsertionSort_SortPairs(std::vector<std::pair<int, int> >res, std::vector<std::pair<int, int> >b)
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

void PmergeMe::V_CreateMainAndPendChain()
{
    Vmain_.push_back(Vpairssorted_[0].second);
    for(unsigned int i = 0; i < Vpairssorted_.size(); i++)
        Vmain_.push_back(Vpairssorted_[i].first);
    for(unsigned int i = 1; i < Vpairssorted_.size(); i++)
        Vpend_.push_back(Vpairssorted_[i].second);    
}

void PmergeMe::V_InsertPend()
{
    int j = 0;
    int index = 0;
    int addedsize = 0;
    while(j < (int)Vpend_.size())
    {
        while(CombinedSequence(index) > (int)Vpend_.size()+1 || CombinedSequence(index) < 2)
           index++;
        int pendpos = CombinedSequence(index) - 2;
        int size = CombinedSequence(index) + addedsize;
        int pos = V_BinarySearch(0, size, Vpend_[pendpos]);
        Vmain_.insert(Vmain_.begin() + pos, Vpend_[pendpos]);
        j++;
        addedsize++;
        index++;
    }
    if (Vstraggler_ != -1)
    {
        int pos = V_BinarySearch(0, Vmain_.size() - 1, Vstraggler_);
        Vmain_.insert(Vmain_.begin() + pos, Vstraggler_);      
    }
}

int PmergeMe::V_BinarySearch(int start, int end, int val)
{
    if (start > end)
        return (start);
    int middle = start + (end - start) / 2;

    if(Vmain_[middle] == val)
        return(middle);
    if(Vmain_[middle] > val)
        return (V_BinarySearch(start, middle - 1, val));
    if(Vmain_[middle] < val)
        return (V_BinarySearch(middle + 1, end, val));
    // FIND POSITION IF NO RANGE LEFT
    if (Vmain_[middle] < val)
        return(middle+1);
    if (Vmain_[middle] > val)
        return(middle-1);
    return(-1);
}

// DEQUE FUNCTIONS

void PmergeMe::D_CreatePairs()
{
    int i = 1;
    while(input_[i] != NULL && input_[i + 1] != NULL)
    {
        int num = std::strtod(input_[i++], NULL);
        int num2 = std::strtod(input_[i], NULL);
        Dpairs_.push_back(std::make_pair(num, num2));
        i++;
    }
    if(input_[i] != NULL)
        Dstraggler_ = std::strtod(input_[i], NULL);
}

void PmergeMe::D_SortInsidePairs()
{
    for(unsigned int i = 0; i < Dpairs_.size(); i++)
    {
        if(Dpairs_[i].first < Dpairs_[i].second)
            std::swap(Dpairs_[i].first, Dpairs_[i].second); 
    }
}

std::deque<std::pair<int, int> >PmergeMe::D_MergeSort_SortPairs(std::deque<std::pair<int, int> > pairs)
{
    std::deque<std::pair<int, int> >tmp;

    if(pairs.size() <= 1)
        return (pairs);
    std::deque<std::pair<int, int> >left(pairs.begin(), pairs.begin() + pairs.size() / 2);
    std::deque<std::pair<int, int> >right(pairs.begin() + pairs.size() / 2, pairs.end());

    left = D_MergeSort_SortPairs(left);
    right = D_MergeSort_SortPairs(right);
    tmp = D_InsertionSort_SortPairs(left, right);
    return(tmp);
}

std::deque<std::pair<int, int> >PmergeMe::D_InsertionSort_SortPairs(std::deque<std::pair<int, int> >res, std::deque<std::pair<int, int> >b)
{
    std::deque<std::pair<int, int> > newres;
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

void PmergeMe::D_CreateMainAndPendChain()
{
    Dmain_.push_back(Dpairssorted_[0].second);
    for(unsigned int i = 0; i < Dpairssorted_.size(); i++)
        Dmain_.push_back(Dpairssorted_[i].first);
    for(unsigned int i = 1; i < Dpairssorted_.size(); i++)
        Dpend_.push_back(Dpairssorted_[i].second);    
}

void PmergeMe::D_InsertPend()
{
    int j = 0;
    int index = 0;
    int addedsize = 0;
    while(j < (int)Dpend_.size())
    {
        while(CombinedSequence(index) > (int)Dpend_.size()+1 || CombinedSequence(index) < 2)
           index++;
        int pendpos = CombinedSequence(index) - 2;
        int size = CombinedSequence(index) + addedsize;
        int pos = D_BinarySearch(0, size, Dpend_[pendpos]);
        Dmain_.insert(Dmain_.begin() + pos, Dpend_[pendpos]);
        j++;
        addedsize++;
        index++;
    }
    if (Dstraggler_ != -1)
    {
        int pos = D_BinarySearch(0, Dmain_.size() - 1, Dstraggler_);
        Dmain_.insert(Dmain_.begin() + pos, Dstraggler_);      
    }
}

int PmergeMe::D_BinarySearch(int start, int end, int val)
{
    if (start > end)
        return (start);
    int middle = start + (end - start) / 2;

    if(Dmain_[middle] == val)
        return(middle);
    if(Dmain_[middle] > val)
        return (D_BinarySearch(start, middle - 1, val));
    if(Dmain_[middle] < val)
        return (D_BinarySearch(middle + 1, end, val));
    // FIND POSITION IF NO RANGE LEFT
    if (Dmain_[middle] < val)
        return(middle+1);
    if (Dmain_[middle] > val)
        return(middle-1);
    return(-1);
}

// FUNCTIONS FOR BOTH

// Jacobstahl sequence + real indexes descending from bigger jacobstahl
int PmergeMe::CombinedSequence(int index)
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
        int tmp = jacobs;
        while(tmp > first+1)
        {
            tmp--;
            i++;
            if (i == index)
                return(tmp);
        }
    }
    return(jacobs);
}

void PmergeMe::MainProcess()
{
    std::clock_t time;
    std::clock_t endtime;
    CheckElements();

    // VECTOR
    time = std::clock();
    V_CreatePairs();
    V_SortInsidePairs();
    if(Vpairs_.size() <= 1)
    {
        Vpairssorted_ = Vpairs_;
        return ;
    }
    Vpairssorted_ = V_MergeSort_SortPairs(Vpairs_);
    V_CreateMainAndPendChain();
    V_InsertPend();
    endtime = std::clock();
    vectime_ = 1000 * 1000 * (endtime - time) / (CLOCKS_PER_SEC); //mikroseconds µs
    
    // DEQUE
    time = std::clock();
    D_CreatePairs();
    D_SortInsidePairs();
    if(Dpairs_.size() <= 1)
    {
        Dpairssorted_ = Dpairs_;
        return ;
    }
    Dpairssorted_ = D_MergeSort_SortPairs(Dpairs_);
    D_CreateMainAndPendChain();
    D_InsertPend();
    endtime = std::clock();
    dequetime_ = 1000 * 1000 * (endtime - time) / (CLOCKS_PER_SEC); //mikroseconds µs


    // OUTPUT
    std::cout << YELLOW "Before:\t" RESET;
    for (unsigned int i = 0; i < Vpairs_.size(); i++)
        std::cout << Vpairs_[i].first << " " << Vpairs_[i].second << " ";
    std::cout << std::endl;
    // getContainerElements(vec_);
    std::cout << YELLOW "After:\t" RESET;
    getContainerElements(Vmain_);
    // std::cout << BLUE "After std::deque:\t" RESET;
    // getContainerElements(Dmain_);
    std::cout << PURPLE "Time to process a range of " << Vmain_.size()
        << " elements with std::vector : " RESET << vectime_ << " µs" << std::endl;
    std::cout << BLUE "Time to process a range of "<< Dmain_.size()
        << " elements with std::deque  : " RESET << dequetime_ << " µs" << std::endl;    
    // TEST();
}

bool PmergeMe::TEST()
{
    for(unsigned int i = 0; i < Vmain_.size(); i++)
    {
        if (i+1 < Vmain_.size() && Vmain_[i] > Vmain_[i+1])
        {
            std::cout << RED "VECTOR ERROR: FINAL CHAIN NOT SORTED" RESET << std::endl;
            return(false);
        }
    }
    std::cout << GREEN "VECTOR FINAL STRING COMPLETELY SORTED" RESET << std::endl;
    for(unsigned int i = 0; i < Dmain_.size(); i++)
    {
        if (i+1 < Dmain_.size() && Dmain_[i] > Dmain_[i+1])
        {
            std::cout << RED "DEQUE ERROR: FINAL CHAIN NOT SORTED" RESET << std::endl;
            return(false);
        }
    }
    std::cout << GREEN "DEQUE FINAL STRING COMPLETELY SORTED" RESET << std::endl;
    return(true);
}

// EXCEPTIONS
const char* PmergeMe::InvalidElement::what() const throw()
{
	return("Error: check elements!");
}