/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/21 18:07:16 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

template <typename T>
class Array {
	public:
		Array() : size_(0) {
			std::cout << "Default Constructor" << std::endl;
			arr_ = new T[0];
		} //creates an empty array

		Array(unsigned int n) : size_(n) {
			std::cout << "Constructor with size" << std::endl;
				arr_ = new T[size_];
		} //creates an array of n elements initialized by default

		// Array(const Array &copyclass) {
		// 	std::cout << "Copy Constructor" << std::endl;
		// 	size_ = copyclass.size_;
		// 	arr_ = new T[size_];
		// 	for (int i = 0; i < size_; i++)
		// 		arr_[i] = copyclass.arr_[i];
		// } //Copy Constructor
		Array(const Array &copyclass) {
			std::cout << "Copy Constructor" << std::endl;
			*this = copyclass; //calls copy assignment operator
		} //Copy Constructor

		Array& operator= (const Array& copyop) {
			std::cout << "Copy Assignment Operator" << std::endl;
			if (this != &copyop)
			{
				delete[] arr_;
				size_ = copyop.size_;
				arr_ = new T[size_];
				for (int i = 0; i < size_; i++)
					arr_[i] = copyop.arr_[i];	
			}
			return (*this);
		} //copy assignment operator

		~Array() {
			std::cout << "Destructor" << std::endl;
			delete[] arr_;
		} //Destructor

		int size() const {
			return (size_);
		} //GETTER

		T& operator[] (int i) {
			if (i >= size_)
				throw IndexOutOfBounds();
			return (arr_[i]);
		}

		class IndexOutOfBounds: public std::exception {
			public:
				virtual const char* what() const throw();
		}; //EXCEPTION
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