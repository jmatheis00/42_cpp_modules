/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:20:21 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/09 15:20:56 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
    public:
        RobotomyRequestForm(); //Default Constructor
		RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &copyclass); //Copy Constructor
		RobotomyRequestForm& operator= (const RobotomyRequestForm& copyop); //copy assignment operator
		~RobotomyRequestForm(); //Destructor
    
        std::string gettarget() const;
    
        void execute(Bureaucrat const &executor);

    private:
        std::string target_;
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& i);

#endif
