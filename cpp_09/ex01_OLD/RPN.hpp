/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:14 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/13 13:15:41 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

class RPN
{
	public:
		~RPN(); //Destructor
		RPN(std::string input);
		bool CheckCharacters();
		void Split();
		void calculate(std::string t);
	private:
		RPN(); //Default Constructor
		RPN(const RPN &copyclass); //Copy Constructor
		RPN& operator= (const RPN& copyop); //copy assignment operator
		std::stack<int>stack_;
		std::string s_;
};

#endif