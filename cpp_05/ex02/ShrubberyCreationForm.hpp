/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:52:34 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/15 08:41:43 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include <fstream>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

// Create a file <target>_shrubbery in the working directory,
// and writes ASCII trees inside it.
class ShrubberyCreationForm : public Form
{
    public:
		ShrubberyCreationForm(); //Default Constructor PRIVATE???
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copyclass); //Copy Constructor
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& copyop); //copy assignment operator
		~ShrubberyCreationForm(); //Destructor

		std::string getTarget() const;
		void executionofform() const;
	private:
		std::string target_;
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& i);

#endif