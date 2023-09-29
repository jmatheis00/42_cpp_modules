/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 08:50:57 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:26:35 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET "\033[0m"	  /* Reset */
#define RED "\033[31m"	  /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define PURPLE "\033[35m" /* Purple */

class Form;

class Intern
{
public:
	Intern();
	Intern(const Intern &copyclass);		 // Copy Constructor
	Intern &operator=(const Intern &copyop); // copy assignment operator
	~Intern();								 // Destructor

	Form *makeForm(std::string formname, std::string target);

	// functionpointer
	Form *shrubbery(std::string target);
	Form *robotomy(std::string target);
	Form *presidential(std::string target);
	Form *(Intern::*funcpoin[3])(std::string target);

private:
	std::string comparison_[3];
};

#endif