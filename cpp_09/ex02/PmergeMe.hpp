/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/07/15 20:09:29 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <fstream>
# include <sstream>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */
#define BLUE     	"\033[34m"              /* Blue */

class PmergeMe
{
	public:
		~PmergeMe(); //Destructor
		PmergeMe(char* ag[]);

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

		template <typename T>
		void CheckAndStoreElements(T& a)
		{
			for(int i = 1; input_[i] != NULL; i++)
			{
				for (int j = 0; input_[i][j] != '\0'; j++)
				{
					if (std::isdigit(input_[i][j]) == false)
						throw InvalidElement();
				}
				double num = std::strtod(input_[i], NULL);
				if (num < 0 || num > std::numeric_limits<int>::max())
					throw InvalidElement();
				a.push_back(num);
			}
		}

		void MainProcess();
		void sortVector(std::vector<int> a);
		std::vector<int> InsertionSort(std::vector<int> res, std::vector<int> b);
		std::vector<int> MergeSort(std::vector<int> a);
		void sortdeque(std::deque<int> a);
		std::deque<int> InsertionSortdeque(std::deque<int> res, std::deque<int> b);
		std::deque<int> MergeSortdeque(std::deque<int> a);

		//EXCEPTION
		class InvalidElement: public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:
		PmergeMe(); //Default Constructor
		PmergeMe(const PmergeMe &copyclass); //Copy Constructor
		PmergeMe& operator= (const PmergeMe& copyop); //copy assignment operator
		char** input_;
		std::vector<int>vec_;
		std::vector<int>final_;
		std::deque<int>deque_;
		std::deque<int>finaldeque_;
		double vectime_;
		double dequetime_;
};


#endif