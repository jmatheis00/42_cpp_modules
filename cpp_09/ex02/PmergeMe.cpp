/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/20 12:04:34 by jmatheis         ###   ########.fr       */
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
    std::cout << "TIME: " << time << std::endl;

    // get first and second
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int>::iterator it = a.begin();
    std::cout << RED "first: " RESET << std::endl;
    if(a.size() <= 1)
    {
        final_ = a;
        return ;
    }
    for(unsigned int i = 0; i <= a.size()/2; i++)
    {
        first.push_back(*it);
        a.erase(it);
        std::cout << first[i] << "\t";
    }
    second = a;
    std::cout << std::endl;
    std::cout << RED "second: " RESET << std::endl;
    for(unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << "\t";
    std::cout << std::endl;

    vecleft_ = MergeSort(first);
    vecright_ = MergeSort(second);

    final_.resize(vecleft_.size() + vecright_.size());

    //HELPER
    // std::cout << GREEN "VEC FINAL SIZE: " RESET << final_.size() << std::endl; 
    std::merge(vecleft_.begin(), vecleft_.end(), vecright_.begin(), vecright_.end(), final_.begin());
    // std::cout << GREEN "VECLEFT" RESET << std::endl;
    // for(unsigned int i = 0; i < vecleft_.size(); i++)
    //     std::cout << vecleft_[i] << "\t";
    // std::cout << std::endl;
    // std::cout << GREEN "VECRIGHT" RESET << std::endl;
    // for(unsigned int i = 0; i < vecright_.size(); i++)
    //     std::cout << vecright_[i] << "\t";
    // std::cout << std::endl;
    std::cout << GREEN "FINAL RESULT" RESET << std::endl;
    for(unsigned int i = 0; i < final_.size(); i++)
        std::cout << final_[i] << "\t";
    std::cout << std::endl;

    double sortedtime = (std::clock() - time) / (CLOCKS_PER_SEC * 1000); //milliseconds
    std::cout << std::fixed << "SORTED TIME: " << sortedtime << " ms" << std::endl;
    std::cout << std::endl;
}

std::vector<int> PmergeMe::MergeSort(std::vector<int>& a)
{
    std::vector<int> tmp;
    if(a.size() <= 1)
    {
        std::cout << RED "EXIT NOW" RESET << std::endl;
        for(unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << std::endl;
        return (a);
    }
    
    std::vector<int>left(a.begin(), a.begin() + a.size() / 2);
    std::cout << "LEFT SIZE " << left.size() << std::endl;
    for(unsigned int i = 0; i < left.size(); i++)
        std::cout << "LEFT: " << left[i] << std::endl;
    std::vector<int>right(a.begin() + a.size() / 2, a.end());
    std::cout << "RIGHT SIZE " << left.size() << std::endl;
    for(unsigned int i = 0; i < right.size(); i++)
        std::cout << "RIGHT: " << right[i] << std::endl;

    std::cout << "A SIZE: " << a.size() << std::endl;
    left = MergeSort(left);
    right = MergeSort(right);
    tmp = InsertionSort(left, right);

    std::cout << RED "AFTER MERGE" RESET << std::endl;
    for(unsigned int i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << "\t";
    std::cout << std::endl;
    return(tmp);
}

std::vector<int> PmergeMe::InsertionSort(std::vector<int> res, std::vector<int> b)
{
    std::vector<int> newres;
    unsigned int j = 0;
    unsigned int i = 0;

    std::cout << YELLOW "IN INSERTION SORT" RESET << std::endl;
    std::cout << "RES" << std::endl;
    for(unsigned int i = 0; i < res.size(); i++)
        std::cout << res[i] << std::endl;
    std::cout << "B" << std::endl;
    for(unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;
    std::cout << "SUM SIZES: " << (res.size() + b.size()) << std::endl;
    while (i < res.size() && j < b.size())
    {
        std::cout << "B: " << b[i] << std::endl;
        std::cout << "RES: " << res[j] << std::endl;
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
    std::cout << "NEWRES" << std::endl;
    for(unsigned int i = 0; i < newres.size(); i++)
        std::cout << newres[i] << std::endl;
    return(newres);
}