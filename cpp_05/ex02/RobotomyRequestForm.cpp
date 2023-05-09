/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:20:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/09 15:22:03 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", 72, 45), target_("Default")
{
    std::cout << "Default Constructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", 72, 45), target_(target)
{
    std::cout << "Constructor with parameters RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copyclass) : Form(copyclass)
{
    target_ = copyclass.target_;
    std::cout << "Copy Constructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& copyop) 
{
	target_ = copyop.target_;
    std::cout << "Copy Assignment Operator RobotomyRequestForm" << std::endl;
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor RobotomyRequestForm: " << getName() << std::endl;
}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& i)
{
	os << "RobotomyRequestForm name: " << i.getName()
        << "\nis signed: " << i.isSignedOrNot()
        << "\ngrade required to sign: " << i.getSignedGrade()
        << "\ngrade required to execute: " << i.getExecutedGrade();
	return (os);
}

// Member functions

std::string RobotomyRequestForm::gettarget() const
{
    return(target_);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
    (void)executor;
}
