/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:23:40 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/01 15:35:26 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form() : name_("Default"), signgrade_(0), executegrade_(0)
{
    issigned_ = false;
    std::cout << "Default Constructor Form" << std::endl;
}

Form::Form(std::string name, int signgrade, int executegrade) : name_(name),
	signgrade_(signgrade), executegrade_(executegrade)
{
    issigned_ = false;
	if (signgrade_ < 1 || executegrade_ < 1)
		throw GradeTooHighException();
	else if (signgrade_ > 150 || executegrade_ < 1)
		throw GradeTooLowException();
    std::cout << "Constructor with parameters Form" << std::endl;
}

Form::Form(const Form &copyclass) : name_(copyclass.name_),
	signgrade_(copyclass.signgrade_), executegrade_(copyclass.executegrade_)
{
    std::cout << "Copy Constructor Form" << std::endl;
}

Form& Form::operator= (const Form& copyop) 
{
	issigned_ = copyop.issigned_;
    std::cout << "Copy Assignment Operator Form" << std::endl;
    return(*this);
}

Form::~Form()
{
    std::cout << "Destructor Form: " << getName() << std::endl;
}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const Form& i)
{
	os << "Form name: " << i.getName()
        << "\nis signed: " << i.isSignedOrNot()
        << "\ngrade required to sign: " << i.getSignedGrade()
        << "\ngrade required to execute: " << i.getExecutedGrade();
	return (os);
}

// OTHER MEMBER FUNCTIONS

std::string Form::getName() const
{
	return(name_);
}

bool Form::isSignedOrNot() const
{
	return(issigned_);
}

int Form::getSignedGrade() const
{
	return(signgrade_);
}

int Form::getExecutedGrade() const
{
	return(executegrade_);
}

void Form::beSigned(Bureaucrat &bureau)
{
	if (bureau.getGrade() > signgrade_)
		throw GradeTooLowException();
	else if (issigned_ == true)
		throw GradeAlreadySignedException();
	else if (bureau.getGrade() <= signgrade_ && issigned_ == false)
		issigned_ = true;
}

// execute forms action of the concrete classes
// check that form is signed & that the grade of the bureaucrat
// attempting to execute the form is high enough
// otherwise throw an appropriate exception
void Form::execute(Bureaucrat const &executor)
{
	Bureaucrat tmp = executor;
}


// EXCEPTION FUNCTIONS
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high, not possible!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low, not possible!");
}

const char *Form::GradeAlreadySignedException::what() const throw()
{
	return ("Grade was already signed!");
}