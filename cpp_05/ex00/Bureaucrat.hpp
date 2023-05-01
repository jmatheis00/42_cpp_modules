#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

class Bureaucrat
{
    public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copyclass); //Copy Constructor
		Bureaucrat& operator= (const Bureaucrat& copyop); //copy assignment operator
		~Bureaucrat(); //Destructor
	
		std::string getName() const;
		int getGrade() const;
		void incrementGrade(); //increment should give a lower grade (Better)
		void decrementGrade(); //decrement should give a higher grade (Worse)

		// Exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:
		Bureaucrat(); //Default Constructor
		std::string const name_;
		int grade_;
		
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& os, const Bureaucrat& i);

#endif