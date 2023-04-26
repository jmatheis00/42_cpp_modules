/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:37:33 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/27 01:13:13 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Default"), grade_(1)
{
    std::cout << "Default Constructor Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
{
	if (grade_ < 1)
		throw GradeTooHighException();
	else if (grade_ > 150)
		throw GradeTooLowException();
    std::cout << "Constructor with parameters Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copyclass)
{
    std::cout << "Copy Constructor Bureaucrat" << std::endl;
	Bureaucrat::operator= (copyclass);
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& copyop)
{
	grade_ = copyop.grade_;
    std::cout << "Copy Assignment Operator Bureaucrat" << std::endl;
    return(*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << RED "Destructor Bureaucrat: " << getName() << RESET << std::endl;
}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const Bureaucrat& i)
{
	os << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return (os);
}

// OTHER MEMBER FUNCTIONS

std::string Bureaucrat::getName() const
{
	return(name_);
}

int Bureaucrat::getGrade() const
{
	return(grade_);
}

void Bureaucrat::incrementGrade()
{
	grade_--;
	if (grade_ < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	grade_++;
	if (grade_ > 150)
		throw GradeTooLowException();
}

// EXCEPTION FUNCTIONS
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high, not possible!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low, not possible!");
}