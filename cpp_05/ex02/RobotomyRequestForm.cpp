/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:37:33 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/15 08:41:17 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::fiftypercent_ = 0;

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", 72, 45), target_("Default")
{
    std::cout << GREEN "RobotomyRequestForm with target " << target_
		<< " woke up" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", 72, 45), target_(target)
{
    std::cout << GREEN "RobotomyRequestForm with target " << target_
		<< " woke up" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copyclass)  : Form(copyclass), target_(copyclass.target_)
{
	fiftypercent_ = copyclass.fiftypercent_;
    std::cout << "Copy Constructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& copyop)
{
	if (this != &copyop)
	{
		fiftypercent_ = copyop.fiftypercent_;
		target_ = copyop.target_;
	}
    std::cout << "Copy Assignment Operator RobotomyRequestForm" << std::endl;
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << GREEN "RobotomyRequestForm with target " << target_ << " died" RESET << std::endl;
}

// GETTER FUNCTIONS
std::string RobotomyRequestForm::getTarget() const
{
	return(target_);
}

// OTHER MEMBER FUNCTIONS
void RobotomyRequestForm::executionofform() const
{
	std::cout << "*** makes some drilling noises ***" << std::endl;
		
	fiftypercent_++;
	if (fiftypercent_ % 2 == 0)
		std::cout << getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << getTarget() << " robotomization failed" << std::endl;

}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& i)
{
	os << "RobotomyRequestForm with target: " << i.getTarget()
		<< ", sign grade: " << i.getSignGrade()
		<< ", execute grade: " << i.getExecuteGrade();
	return (os);
}

