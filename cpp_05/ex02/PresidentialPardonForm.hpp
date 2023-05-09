/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:22:25 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/09 15:22:50 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
    public:
        PresidentialPardonForm(); //Default Constructor
		PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &copyclass); //Copy Constructor
		PresidentialPardonForm& operator= (const PresidentialPardonForm& copyop); //copy assignment operator
		~PresidentialPardonForm(); //Destructor
    
        std::string gettarget() const;
    
        void execute(Bureaucrat const &executor);

    private:
        std::string target_;
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& i);

#endif
