/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/02 13:00:38 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */


// new T[size_]() --> brackets: default value initialization
template <typename T>
class Array
{
	public:
		// DEFAULT CONSTRUCTOR
		Array() : size_(0) {
			std::cout << "Default Constructor" << std::endl;
			arr_ = new T[size_]();
		}
		// CONSTRUCTOR WITH SIZE
		Array(unsigned int n) : size_(n) {
			if (size_ < 0)
				size_ = 0;
			std::cout << "Constructor with size" << std::endl;
			arr_ = new T[size_]();
		}
		// COPY CONSTRUCTOR
		Array(const Array &copyclass) : size_(copyclass.size_) {
			std::cout << "Copy Constructor" << std::endl;
			arr_ = new T[size_];
			for (int i = 0; i < size_; i++)
				arr_[i] = copyclass.arr_[i];
		}
		// COPY ASSIGNMENT OPERATOR
		Array& operator= (const Array& copyop) {
			std::cout << "Copy Assignment Operator" << std::endl;
			if (this != &copyop)
			{
				if(arr_)
					delete[] arr_;
				size_ = copyop.size_;
				arr_ = new T[size_];
				for (int i = 0; i < size_; i++)
					arr_[i] = copyop.arr_[i];	
			}
			return (*this);
		}
		// DESTRUCTOR
		~Array() {
			std::cout << "Destructor" << std::endl;
			delete[] arr_;
		}

		//GETTER
		int size() const {
			return (size_);
		}

		// SUBSCRIPT OPERATOR OVERLOAD
		T& operator[] (int i) {
			if (i >= size_ || i < 0)
				throw IndexOutOfBounds();
			return (arr_[i]);
		}

		// SUBSCRIPT OPERATOR OVERLOAD CONST OBJECTS
		const T& operator[] (int i) const {
			if (i >= size_ || i < 0)
				throw IndexOutOfBounds();
			return (arr_[i]);
		}

		// EXCEPTION
		class IndexOutOfBounds: public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:
		T* arr_;
		int size_;
		
};

template <typename T>
const char* Array<T>::IndexOutOfBounds::what() const throw()
{
    return("Index position doesn't exist in array!");
}

#endif