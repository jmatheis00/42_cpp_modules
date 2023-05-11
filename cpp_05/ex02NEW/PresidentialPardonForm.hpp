/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:52:34 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/11 11:54:58 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

// Informs that <target> has been pardoned by Zaphod Beeblebrox.
class PresidentialPardonForm : public Form
{
    public:
		PresidentialPardonForm(); //Default Constructor PRIVATE???
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copyclass); //Copy Constructor
		PresidentialPardonForm& operator= (const PresidentialPardonForm& copyop); //copy assignment operator
		~PresidentialPardonForm(); //Destructor

		std::string getTarget() const;
	private:
		std::string target_;
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& i);

#endif