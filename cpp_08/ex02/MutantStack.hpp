/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/26 22:29:48 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <iostream>
# include <stack>
# include <list>
# include <vector>
# include <deque>

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
		MutantStack() {
			std::cout << "Default Constructor" << std::endl;
		}

		MutantStack(const MutantStack &copyclass) {
			std::cout << "Copy Constructor" << std::endl;
			std::stack<T>::operator =(copyclass);
		}

		MutantStack& operator= (const MutantStack& copyop) {
			std::cout << "Copy Assignment Operator" << std::endl;
			if (this != &copyop)
			{
				while(this->empty() != true)
					this->pop();
				std::stack<T>::operator =(copyop);
			}
			return(*this);
		}
		
		~MutantStack(){
			std::cout << "Destructor" << std::endl;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {return(this->c.begin());}
		iterator end() {return(this->c.end());}

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const {return(this->c.begin());}
		const_iterator end() const {return(this->c.end());}
};


// underlying container stores every information of the stack elements
// -> it's the base
// usually deque if there is no other container type stated explicitly
// Ein Beispiel dafür wäre std::stack<int, std::vector<int>>,
// wobei std::vector<int> als der zugrundeliegende Container verwendet wird
// c stand for the underlying container -> container_type
// c.begin() is equal to std::stack<T>::container_type::begin()
#endif
