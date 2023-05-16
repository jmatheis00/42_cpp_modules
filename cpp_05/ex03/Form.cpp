/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:37:33 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/16 10:54:29 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("Default"), issigned_(false), signgrade_(1), executegrade_(1)
{
    std::cout << GREEN "Form named " << name_
		<< " woke up" << RESET << std::endl;
}

Form::Form(std::string name, int signgrade, int executegrade) : name_(name), issigned_(false),
	signgrade_(signgrade), executegrade_(executegrade)
{
	if (signgrade_ < 1 || executegrade_ < 1)
		throw GradeTooHighException();
	else if (signgrade_ > 150 || executegrade_ > 150)
		throw GradeTooLowException();
    std::cout << GREEN "Form named " << name_
		<< " woke up" << RESET << std::endl;
}

Form::Form(const Form &copyclass) : name_(copyclass.name_), issigned_(copyclass.issigned_),
	signgrade_(copyclass.signgrade_), executegrade_(copyclass.executegrade_)
{
    std::cout << "Copy Constructor Form" << std::endl;
}

Form& Form::operator= (const Form& copyop)
{
	if (this != &copyop)
	{
		issigned_ = copyop.issigned_;
	}
    std::cout << "Copy Assignment Operator Form" << std::endl;
    return(*this);
}

Form::~Form()
{
    std::cout << GREEN "Form named " << name_ << " died" RESET << std::endl;
}

// GETTER FUNCTIONS
std::string Form::getName() const
{
	return(name_);
}

int Form::getSignGrade() const
{
	return(signgrade_);
}

int Form::getExecuteGrade() const
{
	return(executegrade_);
}

bool Form::getIssignedBool() const
{
	return(issigned_);
}

// OTHER MEMBER FUNCTIONS

void Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() > signgrade_)
		throw GradeTooLowException();
	else if (bur.getGrade() <= signgrade_ && issigned_ == false)
		issigned_ = true;
}

void Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecuteGrade() || getIssignedBool() == false)
		throw ExecutionNotPossible();
	executionofform();
}

	// virtual function
void Form::executionofform() const
{

}

// EXCEPTION FUNCTIONS
const char* Form::GradeTooHighException::what() const throw()
{
	return("Form Exception: Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Form Exception: Grade is too low!");
}

const char* Form::ExecutionNotPossible::what() const throw()
{
	return("Execution not possible, form not signed or grade too low!");
}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const Form& i)
{
	os << i.getName() << ", sign grade: " << i.getSignGrade()
		<< ", execute grade: " <<  i.getExecuteGrade()
		<< ", is signed: " << i.getIssignedBool();
	return (os);
}

