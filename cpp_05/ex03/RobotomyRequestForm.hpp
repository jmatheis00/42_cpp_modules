/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:52:39 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:28:14 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
#include "Bureaucrat.hpp"

#define RESET "\033[0m"	  /* Reset */
#define RED "\033[31m"	  /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define PURPLE "\033[35m" /* Purple */

class Bureaucrat;

// Makes some drilling noises.
// Then, informs that <target> has been robotomized successfully 50% of the time.
// Otherwise, informs that the robotomy failed.
class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(); // Default Constructor
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copyclass);		   // Copy Constructor
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copyop); // copy assignment operator
	virtual ~RobotomyRequestForm();									   // Destructor

	std::string getTarget() const;
	void executionofform() const;

private:
	std::string target_;
	static int fiftypercent_;
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &i);

#endif