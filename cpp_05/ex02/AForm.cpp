/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:37:33 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/16 10:51:18 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name_("Default"), issigned_(false), signgrade_(1), executegrade_(1)
{
    std::cout << GREEN "AForm named " << name_
		<< " woke up" << RESET << std::endl;
}

AForm::AForm(std::string name, int signgrade, int executegrade) : name_(name), issigned_(false),
	signgrade_(signgrade), executegrade_(executegrade)
{
	if (signgrade_ < 1 || executegrade_ < 1)
		throw GradeTooHighException();
	else if (signgrade_ > 150 || executegrade_ > 150)
		throw GradeTooLowException();
    std::cout << GREEN "AForm named " << name_
		<< " woke up" << RESET << std::endl;
}

AForm::AForm(const AForm &copyclass) : name_(copyclass.name_), issigned_(copyclass.issigned_),
	signgrade_(copyclass.signgrade_), executegrade_(copyclass.executegrade_)
{
    std::cout << "Copy Constructor AForm" << std::endl;
}

AForm& AForm::operator= (const AForm& copyop)
{
	if (this != &copyop)
	{
		issigned_ = copyop.issigned_;
	}
    std::cout << "Copy Assignment Operator AForm" << std::endl;
    return(*this);
}

AForm::~AForm()
{
    std::cout << GREEN "AForm named " << name_ << " died" RESET << std::endl;
}

// GETTER FUNCTIONS
std::string AForm::getName() const
{
	return(name_);
}

int AForm::getSignGrade() const
{
	return(signgrade_);
}

int AForm::getExecuteGrade() const
{
	return(executegrade_);
}

bool AForm::getIssignedBool() const
{
	return(issigned_);
}

// OTHER MEMBER FUNCTIONS

void AForm::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() > signgrade_)
		throw GradeTooLowException();
	else if (bur.getGrade() <= signgrade_ && issigned_ == false)
		issigned_ = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecuteGrade() || getIssignedBool() == false)
		throw ExecutionNotPossible();
	executionofform();
}

// virtual function
void AForm::executionofform() const
{

}

// EXCEPTION FUNCTIONS
const char* AForm::GradeTooHighException::what() const throw()
{
	return("AForm Exception: Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("AForm Exception: Grade is too low!");
}

const char* AForm::ExecutionNotPossible::what() const throw()
{
	return("Execution not possible, form not signed or grade too low!");
}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const AForm& i)
{
	os << i.getName() << ", sign grade: " << i.getSignGrade()
		<< ", execute grade: " <<  i.getExecuteGrade()
		<< ", is signed: " << i.getIssignedBool();
	return (os);
}

