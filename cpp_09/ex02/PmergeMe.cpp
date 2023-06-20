/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/20 12:19:36 by jmatheis         ###   ########.fr       */
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
        vec_.push_back(strtod(ag[i], NULL));
        list_.push_back(strtod(ag[i], NULL));
    }
    std::cout << "Before:\t";
    getContainerElements(vec_);
    sortContainer(vec_);
    // getContainerElements(list_);

//    getTokens(ag);
}

void PmergeMe::sortContainer(std::vector<int> a)
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

    std::cout << GREEN "After: " RESET;
    for(unsigned int i = 0; i < final_.size(); i++)
        std::cout << final_[i] << " ";
    std::cout << std::endl;

    std::clock_t endtime = std::clock();
    double sortedtime = (endtime - time) / (CLOCKS_PER_SEC * 1000 * 1000); //mikroseconds µs
    std::cout << std::fixed << "SORTED TIME: " << sortedtime << " µs" << std::endl;
}

std::vector<int> PmergeMe::MergeSort(std::vector<int>& a)
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
        {
            newres.push_back(res[i]);
            i++;
        }
        else
        {
            newres.push_back(b[j]);
            j++;
        }
    }
    // Füge die restlichen Elemente von res hinzu, falls vorhanden
    while (i < res.size())
    {
        newres.push_back(res[i]);
        i++;
    }
    // Füge die restlichen Elemente von b hinzu, falls vorhanden
    while (j < b.size())
    {
        newres.push_back(b[j]);
        j++;
    }
    return(newres);
}