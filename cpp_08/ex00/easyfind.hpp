/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/26 11:18:50 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

class NoOccurenceFound: public std::exception {
	public:
		virtual const char* what() const throw(){
			return("Occurence not found in Container!");
		}
};

template <typename T>
int easyfind(T a, int i)
{
	typename T::const_iterator it = std::find(a.begin(), a.end(), i);
	
	if(it != a.end())
		return (*it);
	else
		throw NoOccurenceFound();
}

#endif