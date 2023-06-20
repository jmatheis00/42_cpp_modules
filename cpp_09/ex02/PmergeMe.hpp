/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/20 11:32:26 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <fstream>
# include <sstream>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */


class PmergeMe
{
	public:
		~PmergeMe(); //Destructor
		PmergeMe(char* ag[]);
		void getTokens();
		// PRINTS 0 AT BEGINNING???
		template <typename T>
		void getContainerElements(T a)
		{
			typename T::const_iterator it = a.begin();
			while(it < a.end())
			{
				std::cout << *it << " ";
				it++;
			}
			std::cout << std::endl;
		}

		// take two lists and put them together
		std::vector<int> InsertionSort(std::vector<int> res, std::vector<int> b);

		// recursive: part list with 2
		// until only one element left
		std::vector<int> MergeSort(std::vector<int>& a);
		
		// IMPLEMENT TIME TRACKING UNTIL SORTED
		void sortContainer(std::vector<int> a);

	private:
		PmergeMe(); //Default Constructor
		PmergeMe(const PmergeMe &copyclass); //Copy Constructor
		PmergeMe& operator= (const PmergeMe& copyop); //copy assignment operator
		std::vector<int>vec_;
		std::vector<int>vecleft_;
		std::vector<int>vecright_;
		std::vector<int>final_;
		std::list<int>list_;
		// std::multimap
};


#endif