/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/07/22 14:12:47 by jmatheis         ###   ########.fr       */
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

		void CheckElements()
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
			}
		}

		// VECTORFUNCTIONS
		void V_CreateAndSortInsidePairs();
		std::vector<std::pair<int, int> >V_MergeSort_SortPairs(std::vector<std::pair<int, int> > pairs);
		std::vector<std::pair<int, int> >V_InsertionSort_SortPairs(std::vector<std::pair<int, int> >res, std::vector<std::pair<int, int> >b);
		void V_CreateMainAndPendChain();
		void V_InsertPend();
		int V_BinarySearch(int start, int end, int val);

		// DEQUEFUNCTIONS
		void D_CreateAndSortInsidePairs();
		std::deque<std::pair<int, int> >D_MergeSort_SortPairs(std::deque<std::pair<int, int> > pairs);
		std::deque<std::pair<int, int> >D_InsertionSort_SortPairs(std::deque<std::pair<int, int> >res, std::deque<std::pair<int, int> >b);
		void D_CreateMainAndPendChain();
		void D_InsertPend();
		int D_BinarySearch(int start, int end, int val);

		// FUNCTIONS FOR BOTH
		void Output(int dequetime, int vectime);
		int CombinedSequence(int index);
		void MainProcess();
		bool TEST();

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

		// DEQUE
		int Dstraggler_;
		std::deque<std::pair<int,int> >Dpairs_;
		std::deque<std::pair<int,int> >Dpairssorted_;
		std::deque<int>Dmain_;
		std::deque<int>Dpend_;
		
		// VECTOR
		int Vstraggler_;
		std::vector<int>before_;
		std::vector<std::pair<int,int> >Vpairs_;
		std::vector<std::pair<int,int> >Vpairssorted_;
		std::vector<int>Vmain_;
		std::vector<int>Vpend_;
};


#endif