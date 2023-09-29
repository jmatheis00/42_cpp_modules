/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:37:33 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:21:28 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Default"), grade_(75)
{
	std::cout << GREEN "Bureaucrat named " << name_
			  << " woke up with grade " << grade_ << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
{
	if (grade_ < 1)
		throw GradeTooHighException();
	else if (grade_ > 150)
		throw GradeTooLowException();
	std::cout << GREEN "Bureaucrat named " << name_
			  << " woke up with grade " << grade_ << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copyclass) : name_(copyclass.name_), grade_(copyclass.grade_)
{
	std::cout << "Copy Constructor Bureaucrat" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copyop)
{
	if (this != &copyop)
	{
		grade_ = copyop.grade_;
	}
	std::cout << "Copy Assignment Operator Bureaucrat" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREEN "Bureaucrat named " << name_
			  << " with grade " << grade_ << " died" RESET << std::endl;
}

// GETTER FUNCTIONS
const std::string Bureaucrat::getName() const
{
	return (name_);
}

int Bureaucrat::getGrade() const
{
	return (grade_);
}

// OTHER MEMBER FUNCTIONS
// 1 is the highest grade
void Bureaucrat::incrementGrade()
{
	if (grade_ <= 1)
		throw GradeTooHighException();
	grade_--;
}

// 150 is the lowest grade
void Bureaucrat::decrementGrade()
{
	if (grade_ >= 150)
		throw GradeTooLowException();
	grade_++;
}

// EXCEPTION FUNCTIONS
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade is too low!");
}

// OUTPUT OPERATOR OVERLOADING
std::ostream &operator<<(std::ostream &os, const Bureaucrat &i)
{
	os << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return (os);
}
