/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 08:50:54 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:26:28 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << GREEN "Default Constructor Intern " << RESET << std::endl;
	comparison_[0] = "shrubbery creation";
	comparison_[1] = "robotomy request";
	comparison_[2] = "presidential pardon";
}

Intern::Intern(const Intern &copyclass)
{
	for (int i = 0; i < 3; i++)
		comparison_[i] = copyclass.comparison_[i];
	std::cout << "Copy Constructor Intern" << std::endl;
}

Intern &Intern::operator=(const Intern &copyop)
{
	if (this != &copyop)
	{
		for (int i = 0; i < 3; i++)
			comparison_[i] = copyop.comparison_[i];
	}
	std::cout << "Copy Assignment Operator Intern" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << GREEN "Destructor Intern " << RESET << std::endl;
}

Form *Intern::makeForm(std::string formname, std::string target)
{
	funcpoin[0] = &Intern::shrubbery;
	funcpoin[1] = &Intern::robotomy;
	funcpoin[2] = &Intern::presidential;

	for (int i = 0; i < 3; i++)
	{
		if (comparison_[i] == formname)
		{
			std::cout << "Intern creates " << formname
					  << " with target " << target << std::endl;
			return ((this->*funcpoin[i])(target));
		}
	}
	std::cout << formname << " doesn't exist" << std::endl;
	return (NULL);
}

Form *Intern::shrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::robotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::presidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}