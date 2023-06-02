/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/02 17:17:26 by jmatheis         ###   ########.fr       */
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

#endif