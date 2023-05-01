/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:51:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/01 15:27:49 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

class Form;

class Bureaucrat
{
    public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copyclass); //Copy Constructor
		Bureaucrat& operator= (const Bureaucrat& copyop); //copy assignment operator
		~Bureaucrat(); //Destructor
	
		std::string getName() const;
		int getGrade() const;
		void incrementGrade(); //increment should give a lower grade (Better)
		void decrementGrade(); //decrement should give a higher grade (Worse)

		void signForm(Form &forms);
		void executeForm(Form const& form);

		// Exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:
		Bureaucrat(); //Default Constructor
		std::string const name_;
		int grade_;
		
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& os, const Bureaucrat& i);

#endif