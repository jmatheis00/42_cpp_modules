/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:37:33 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:25:12 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target_("Default")
{
	std::cout << GREEN "ShrubberyCreationForm with target " << target_
			  << " woke up" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), target_(target)
{
	std::cout << GREEN "ShrubberyCreationForm with target " << target_
			  << " woke up" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copyclass) : AForm(copyclass), target_(copyclass.target_)
{
	std::cout << "Copy Constructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copyop)
{
	if (this != &copyop)
	{
		target_ = copyop.target_;
	}
	std::cout << "Copy Assignment Operator ShrubberyCreationForm" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GREEN "ShrubberyCreationForm with target " << target_ << " died" RESET << std::endl;
}

// GETTER FUNCTIONS
std::string ShrubberyCreationForm::getTarget() const
{
	return (target_);
}

// OTHER MEMBER FUNCTIONS
void ShrubberyCreationForm::executionofform() const
{
	std::string outfile = getTarget() + "_shrubbery";
	std::ofstream newf(outfile);
	newf << ".. . .  . .. .  . .. .  . .. .  . .. .  . .. .  . .. .  . .. .  . .. .  . .. ..\n"
		 << ".. .  . .. .  . .. .  . .. .  . .. .  . .% .  . .. .  . .. .  . .. .  . .. .  .\n"
		 << ".. .  . .. .  . .. .  . .. .%%( .*../%%&(.(/*#%(..(%, . .. .  . .. .  . .. .  .\n"
		 << ".. .  . .. .  . .. .  . .. .*/#((%(%%%#%.%%%%%&#&(%(/   .. .  . .. .  . .. .  .\n"
		 << ".. .  . .. .  . .. . %*%,. &(%#####%&(#%&%##(%(&%  ,%#%*(%#.  . .. .  . .. .  .\n"
		 << ".. .  . .. .  . .. /  #.%& &%&//%&%%&&%##%/%(%#&%%,(&%(((&..  . .. .  . .. .  .\n"
		 << ".. .  . .. .  . .(%%%%%( ###%#((%#%&&#,#&&&%#/#%&#,%%(#* %#%  . .. .  . .. .  .\n"
		 << ".. .  . .. .  . #&##% *%*%&(#%%%%%##%%*%./%.&&##%%/#&/%%##%.. . .. .  . .. .  .\n"
		 << ".. .  . .. .  . .%%(#%&&.&&&*%& #(&%/#%#%#&#*#%&#&%&#  %*#*#&/. .. .  . .. .  .\n"
		 << ".  .. .  . .. . &. &/&%#/%%&%%&%#&#(%(.&%&%%%%%(%% #(%#%/,./&%* #(... .  . .. .\n"
		 << ".  .. .  . .. .  . . %%%%&&&%(%&&&%&%&%/&&&&%%%#/(%(&%&##%&%,%((###*. .  . .. .\n"
		 << ".  .. .  . .. .  ./&,#%&&% %&&&&%*%%%%%&&#,%%#,%(%%%(&&%&&#%%((#,. .. .  . .. .\n"
		 << ".  .. .  . .%&#%%%&&&&%/#%&&%#/&*/%&#&#&& %##//&/&(/&&%%%(&#&#(&#. .. .  . .. .\n"
		 << ".  .. .  . .. %&%&%###%%%%%&&%,# #&&&*/((%##%%%*#%%&%%%%&/##%&%( /#(/%/  . .. .\n"
		 << ".  .. .  . .. . #.%&%%&&%%&&#&&&&&%&###(&&%%#%%%&&%/#%%/&%%%##%(%(%(. .  . .. .\n"
		 << ".  .. .  . .,&&& &&%#%%&#%&%& #&#.&&&%&&%%&%&&&&&&%%%%%&%&#&&&%  . .. .  . .. .\n"
		 << ".  .. .  . ..  *&..% #%&&&#&,&&&&&%.%&#%%#&&%*&%&&%&&&&%%&&#%%#/(, .. .  . .. .\n"
		 << ".. .  . .. .  .  &&&  &&&&%** . & %&%&#, & #&%,,&(#&&%&(%/&&%&##%. .  . .. .  .\n"
		 << ".. .  . .. .  . (*%&&%%&%%&% %%, .//%&&&%&%%#(#*#&&%/&& (#% *% %%, .  . .. .  .\n"
		 << ".. .  . .. .  ./&&&&.(% .%&&&&,%%&&,%%&&#%&&&&##(((&%/(&#(%%%%//....  . .. .  .\n"
		 << ".. .  . .. .  . .. .  *,*(,%#%&%&%&&&%*%## &,&(%(#&%/%#%&(,.%%% &(/%# . .. .  .\n"
		 << ".. .  . .. .  . .. . .#&&*..  &&(&*&&% (( .&&&#%&#&*%/&%&&#&,(&&%%,#  . .. .  .\n"
		 << ".. .  . .. .  . .%%%%#(&%&%&&%.&, (&&&&&%%%&  /%(&%(((&&/. && &%%. .  . .. .  .\n"
		 << ".. .  . .. .  . ..   #&%.. .  . .. .  . &#%#  . ,. .  .*.. .  . .. .  . .. .  .\n"
		 << ".. .  . .. .  . .. .  . .. .  . .. .  . %&%/  . .. .  . .. .  . .. .  . .. .  .\n"
		 << ".  .. .  . .. .  . .. .  . .. .  . .. . %%# . .  . .. .  . .. .  . .. .  . .. .\n"
		 << ".  .. .  . .. .  . .. .  . .. .  . .. . (&# . .  . .. .  . .. .  . .. .  . .. .\n"
		 << ".  .. .  . .. .  . .. .  . .. .  . .. . %(& . .  . .. .  . .. .  . .. .  . .. .\n"
		 << ".  .. .  . .. .  . .. .  . .. .  . .. . ##) . .  . .. .  . .. .  . .. .  . .. .\n"
		 << ".  .. .  . .. .  . .. .  . .. .  . .. ./#(& . .  . .. .  . .. .  . .. .  . .. .\n"
		 << ".  .. .  . .. .  . .. .  . .. .  . .. .#((# . .  . .. .  . .. .  . .. .  . .. .\n"
		 << ".  .. .  . .. .  . .. .  . .. .  . .. . .. .. .  . .. .  . .. .  . .. .  . .. ."
		 << std::endl;
	newf.close();
}

// OUTPUT OPERATOR OVERLOADING
std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &i)
{
	os << "ShrubberyCreationForm with target: " << i.getTarget()
	   << ", sign grade: " << i.getSignGrade()
	   << ", execute grade: " << i.getExecuteGrade();
	return (os);
}
