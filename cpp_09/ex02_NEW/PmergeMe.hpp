/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/07/18 16:42:14 by jmatheis         ###   ########.fr       */
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
		void CreateVectorPairs();
		void SortInsidePairs();
		std::vector<std::pair<int, int> >MergeSort_SortPairs(std::vector<std::pair<int, int> > pairs);
		std::vector<std::pair<int, int> >InsertionSort_SortPairs(std::vector<std::pair<int, int> >res, std::vector<std::pair<int, int> >b);
		void CreateMainAndPendChain();
		std::vector<std::pair<int, int> >BinarySearch(std::vector<std::pair<int, int> > pairs);

		int CombinedSequence(int index);
		int Jacobstahl(int index);
		void InsertPend();
		void MainProcess();
		int BinarySearch(int start, int end, int val);

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
		// std::vector<std::vector<int> >vector_;
		std::vector<int>bigger_;
		std::vector<int>smaller_;
		int straggler_;
		std::vector<std::pair<int,int> >vecpairs_;
		std::vector<std::pair<int,int> >vecpairssorted_;
		std::vector<int>main_;
		std::vector<int>pend_;
};


#endif