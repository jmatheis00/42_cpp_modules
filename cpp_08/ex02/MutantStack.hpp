/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/08 12:39:02 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <iostream>
# include <stack>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

// template class derived from std::stack<T>
// all functions from stack usuable through class
// Bitte beachte, dass this->c auf den 
// zugrunde liegenden Container von std::stack verweist,
// dessen tatsächlicher Name abhängig von der Implementierung
//  von std::stack ist. In der Regel ist es ein std::deque.
template <typename T>
class MutantStack : public std::stack<T>
{
    public:
		// defines new iterator for type T
		// two nested typedefs (iterator)
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		// this->c pointer to container of std::stack<T>
		iterator begin() {return(this->c.begin());}
		iterator end() {return(this->c.end());}
		const_iterator begin() const {return(this->c.begin());}
		const_iterator end() const {return(this->c.end());}
};


// typedef: assigning an alternative name to  a specific type
// typename: used to tell compiler
// that std::stack<T>::container_type::iterator
// is a valid type and should be named as iterator.
// without typename: compiler would not recognize iterator as type automatically
// -> typename helps compiler to understand the right context
// and to assign the right type

// std::stack = a container adapter class
// -> takes another existing container as base
// which provides a LIFO (Last-In-First-Out) Data structure
// the container used as base can be accessed via
// the container_type member type of the std::stack class 
// container_type = an alias for the underlying container
// which is by default a std::deque

// underlying container stores every information of the stack elements
// -> it's the base
// usually deque if there is no other container type stated explicitly
// Ein Beispiel dafür wäre std::stack<int, std::vector<int>>,
// wobei std::vector<int> als der zugrundeliegende Container verwendet wird
// c stand for the underlying container -> container_type
// c.begin() is equal to std::stack<T>::container_type::begin()
#endif
