/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:37:33 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/15 08:41:07 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential", 25, 5), target_("Default")
{
    std::cout << GREEN "PresidentialPardonForm with target " << target_
		<< " woke up" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential", 25, 5), target_(target)
{
    std::cout << GREEN "PresidentialPardonForm with target " << target_
		<< " woke up" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copyclass)  : Form(copyclass), target_(copyclass.target_)
{
    std::cout << "Copy Constructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& copyop)
{
	if (this != &copyop)
	{
		target_ = copyop.target_;
	}
    std::cout << "Copy Assignment Operator PresidentialPardonForm" << std::endl;
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << GREEN "PresidentialPardonForm with target " << target_ << " died" RESET << std::endl;
}

// GETTER FUNCTIONS
std::string PresidentialPardonForm::getTarget() const
{
	return(target_);
}

// OTHER MEMBER FUNCTIONS
void PresidentialPardonForm::executionofform() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebox" << std::endl;
}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& i)
{
	os << "PresidentialPardonForm with target: " << i.getTarget()
		<< ", sign grade: " << i.getSignGrade()
		<< ", execute grade: " << i.getExecuteGrade();
	return (os);
}
