/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:23:05 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:23:09 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

#define RESET "\033[0m"	  /* Reset */
#define RED "\033[31m"	  /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define PURPLE "\033[35m" /* Purple */

class Bureaucrat;

class Form
{
public:
	Form(std::string name, int signgrade, int executegrade);
	Form(const Form &copyclass);		 // Copy Constructor
	Form &operator=(const Form &copyop); // copy assignment operator
	~Form();							 // Destructor

	// GETTER
	std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool getIssignedBool() const;

	// OTHER
	void beSigned(Bureaucrat &bur);

	// EXCEPTIONS
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	Form(); // Default Constructor
	const std::string name_;
	bool issigned_;
	const int signgrade_;
	const int executegrade_;
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream &operator<<(std::ostream &os, const Form &i);

#endif