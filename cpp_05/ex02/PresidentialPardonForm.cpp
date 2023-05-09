/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:23:01 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/09 15:23:36 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential", 25, 5), target_("Default")
{
    std::cout << "Default Constructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential", 25, 5), target_(target)
{
    std::cout << "Constructor with parameters PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copyclass) : Form(copyclass)
{
    target_ = copyclass.target_;
    std::cout << "Copy Constructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& copyop) 
{
	target_ = copyop.target_;
    std::cout << "Copy Assignment Operator PresidentialPardonForm" << std::endl;
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor PresidentialPardonForm: " << getName() << std::endl;
}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& i)
{
	os << "PresidentialPardonForm name: " << i.getName()
        << "\nis signed: " << i.isSignedOrNot()
        << "\ngrade required to sign: " << i.getSignedGrade()
        << "\ngrade required to execute: " << i.getExecutedGrade();
	return (os);
}

// Member functions

std::string PresidentialPardonForm::gettarget() const
{
    return(target_);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)
{
    (void)executor;
}
