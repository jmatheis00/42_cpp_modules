/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/07 19:06:36 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

class Span
{
    public:
		Span(); //Default Constructor
		Span(unsigned int N);
		Span(const Span &copyclass); //Copy Constructor
		Span& operator= (const Span& copyop); //copy assignment operator
		~Span(); //Destructor

		// GETTER
		void getSpan();
		int getSize();
		// OTHER
		void addNumber(int i); //add single number to Span
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void addmanyNumbers(std::vector<int> range); //add many number to Span
		void addmanyNumbers(std::vector<int>::iterator itb, std::vector<int>::iterator ite); //add many number to Span

		// EXCEPTIONS
		class SpanIsAlreadyFilled: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NoSpanFound: public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		unsigned int N_;
		std::vector<int> vec_;
};

#endif