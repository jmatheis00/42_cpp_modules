/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:38:52 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/01 19:27:22 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery", 145, 137), target_("Default")
{
    std::cout << "Default Constructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery", 145, 137), target_(target)
{
    std::cout << "Constructor with parameters ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copyclass) : Form(copyclass)
{
    target_ = copyclass.target_;
    std::cout << "Copy Constructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& copyop) 
{
	target_ = copyop.target_;
    std::cout << "Copy Assignment Operator ShrubberyCreationForm" << std::endl;
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor ShrubberyCreationForm: " << getName() << std::endl;
}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& i)
{
	os << "ShrubberyCreationForm name: " << i.getName()
        << "\nis signed: " << i.isSignedOrNot()
        << "\ngrade required to sign: " << i.getSignedGrade()
        << "\ngrade required to execute: " << i.getExecutedGrade();
	return (os);
}

// Member functions

std::string ShrubberyCreationForm::gettarget() const
{
    return(target_);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
    (void)executor;
}