/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:24:12 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:24:14 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

#define RESET "\033[0m"	  /* Reset */
#define RED "\033[31m"	  /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define PURPLE "\033[35m" /* Purple */

class AForm;

class Bureaucrat
{
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copyclass);		 // Copy Constructor
	Bureaucrat &operator=(const Bureaucrat &copyop); // copy assignment operator
	~Bureaucrat();									 // Destructor

	// GETTER
	const std::string getName() const;
	int getGrade() const;

	// OTHER
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &fo);
	void executeForm(AForm const &form);

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
	Bureaucrat(); // Default Constructor
	const std::string name_;
	int grade_;
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream &operator<<(std::ostream &os, const Bureaucrat &i);

#endif