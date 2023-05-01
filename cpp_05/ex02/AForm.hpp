/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:51:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/01 15:56:24 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

class Bureaucrat;

class Form
{
    public:
		Form(std::string name, int signgrade, int executegrade);
        Form(); //Default Constructor		
		Form(const Form &copyclass); //Copy Constructor
		Form& operator= (const Form& copyop); //copy assignment operator
		virtual ~Form(); //Destructor

        // Getters
		std::string getName() const;
		bool isSignedOrNot() const;
		int getSignedGrade() const;
		int getExecutedGrade() const;

        void beSigned(Bureaucrat &bureau);
		virtual void execute(Bureaucrat const &executor) = 0;
	
        // Exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeAlreadySignedException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
	
	private:
		std::string const name_;
        bool issigned_;
        int const signgrade_;
        int const executegrade_;

};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& os, const Form& i);

#endif