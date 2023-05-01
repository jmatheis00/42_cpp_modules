/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:38:49 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/01 19:25:55 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
    public:
        ShrubberyCreationForm(); //Default Constructor
		ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copyclass); //Copy Constructor
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& copyop); //copy assignment operator
		~ShrubberyCreationForm(); //Destructor
    
        std::string gettarget() const;
    
        void execute(Bureaucrat const &executor);

    private:
        std::string target_;
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& i);

#endif