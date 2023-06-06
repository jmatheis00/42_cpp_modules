/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/06 13:35:03 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <ostream>

class Person
{
	public:
		Person() : name_("default Person") {
			std::cout << "Default Constructor Person" << std::endl;
		}
		Person(std::string name) : name_(name) {
			std::cout << "Person Constructor with name" << std::endl;
		}
		Person(const Person &copyclass) : name_(copyclass.name_) {
			std::cout << "Copy Constructor Person" << std::endl;
		}
		Person& operator= (const Person& copyop) {
			std::cout << "Copy Assignment Operator Person" << std::endl;
			if (this != &copyop)
				name_ = copyop.name_;
			return (*this);
		}
        ~Person(){
			std::cout << "Destructor Person" << std::endl;
		}
        std::string getname() const {return(name_);}
    private:
        std::string name_;
};

std::ostream& operator<<(std::ostream& os, const Person& i){os << i.getname(); return(os);}


int main()
{
    {
        std::cout << YELLOW "CLASS Array test" RESET << std::endl;
        std::cout << PURPLE "Constructor with size" RESET << std::endl;
        Array<Person> test1(5);
        std::cout << "size of test1: " << test1.size() << std::endl;
        std::cout << PURPLE "Default Constructor" RESET << std::endl;
        Array<Person> test2;
        std::cout << "size of test2: " << test2.size() << std::endl;
        std::cout << PURPLE "Filling values + out of range test" RESET << std::endl;
        try
        {
            test1[0] = Person("Bob");
            test1[1] = Person("Amy");
            test1[2] = Person("Marvin");
            test1[3] = Person("Anna");
            test1[4] = Person("Tim");
            test1[5] = Person("Chiara");  
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
        std::cout << YELLOW "\nDEEP COPY TEST" RESET << std::endl;
        std::cout << PURPLE "copy constructor" RESET << std::endl;
        Array<Person> test3(test1);
        std::cout << PURPLE "copy assignment operator" RESET << std::endl;
        test2 = test1;
        std::cout << PURPLE "values test1" RESET << std::endl;
        for (int i = 0; i < test1.size(); i++)
            std::cout << test1[i] << std::endl;
        std::cout << PURPLE "values test2" RESET << std::endl;
        for (int i = 0; i < test2.size(); i++)
            std::cout << test2[i] << std::endl;
        std::cout << PURPLE "values test3" RESET << std::endl;
        for (int i = 0; i < test3.size(); i++)
            std::cout << test3[i] << std::endl;
        std::cout << PURPLE "change of values in test1" RESET << std::endl;
        for (int i = 0; i < test1.size(); i++)
            test1[i] = Person("NO NAME");
        std::cout << PURPLE "values test1 (changed)" RESET << std::endl;
        for (int i = 0; i < test1.size(); i++)
            std::cout << test1[i] << std::endl;
        std::cout << PURPLE "values test2" RESET << std::endl;
        for (int i = 0; i < test2.size(); i++)
            std::cout << test2[i] << std::endl;
        std::cout << PURPLE "values test3" RESET << std::endl;
        for (int i = 0; i < test3.size(); i++)
            std::cout << test3[i] << std::endl;
        std::cout << PURPLE "Destructors" RESET << std::endl;
    }
    {
        std::cout << YELLOW "INT Array test" RESET << std::endl;
        std::cout << PURPLE "Constructor with size" RESET << std::endl;
        Array<int> test1(5);
        std::cout << "size of test1: " << test1.size() << std::endl;
        std::cout << PURPLE "Default Constructor" RESET << std::endl;
        Array<int> test2;
        std::cout << "size of test2: " << test2.size() << std::endl;
        std::cout << PURPLE "Filling values + out of range test" RESET << std::endl;
        try
        {
            test1[0] = 1;
            test1[1] = 2;
            test1[2] = 3;
            test1[3] = 4;
            test1[4] = 5;
            test1[5] = 6;  
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
        std::cout << YELLOW "\nDEEP COPY TEST" RESET << std::endl;
        std::cout << PURPLE "copy constructor" RESET << std::endl;
        Array<int> test3(test1);
        std::cout << PURPLE "copy assignment operator" RESET << std::endl;
        test2 = test1;
        std::cout << PURPLE "values test1" RESET << std::endl;
        for (int i = 0; i < test1.size(); i++)
            std::cout << test1[i] << std::endl;
        std::cout << PURPLE "values test2" RESET << std::endl;
        for (int i = 0; i < test2.size(); i++)
            std::cout << test2[i] << std::endl;
        std::cout << PURPLE "values test3" RESET << std::endl;
        for (int i = 0; i < test3.size(); i++)
            std::cout << test3[i] << std::endl;
        std::cout << PURPLE "change of values in test1" RESET << std::endl;
        for (int i = 0; i < test1.size(); i++)
        {
            test1[i] = -1;
            std::cout << test1[i] << std::endl;
        }
        std::cout << PURPLE "values test2" RESET << std::endl;
        for (int i = 0; i < test2.size(); i++)
            std::cout << test2[i] << std::endl;
        std::cout << PURPLE "values test3" RESET << std::endl;
        for (int i = 0; i < test3.size(); i++)
            std::cout << test3[i] << std::endl;
        std::cout << PURPLE "Destructors" RESET << std::endl;
    }
    // {
    //     std::cout << YELLOW "STRING Array test" RESET << std::endl;
    //     std::cout << PURPLE "Constructor with size" RESET << std::endl;
    //     Array<std::string> test1(5);
    //     std::cout << "size of test1: " << test1.size() << std::endl;
    //     std::cout << PURPLE "Default Constructor" RESET << std::endl;
    //     Array<std::string> test2;
    //     std::cout << "size of test2: " << test2.size() << std::endl;
    //     std::cout << PURPLE "Filling values + out of range test" RESET << std::endl;
    //     try
    //     {
    //         test1[0] = "value position 0";
    //         test1[1] = "value position 1";
    //         test1[2] = "value position 2";
    //         test1[3] = "value position 3";
    //         test1[4] = "value position 4";
    //         test1[5] = "value position 5"; 
    //     }
    //     catch(const std::exception& e)
    //     {
    //         std::cerr << RED << e.what() << RESET << std::endl;
    //     }
    //     std::cout << YELLOW "\nDEEP COPY TEST" RESET << std::endl;
    //     std::cout << PURPLE "copy constructor" RESET << std::endl;
    //     Array<std::string> test3(test1);
    //     std::cout << PURPLE "copy assignment operator" RESET << std::endl;
    //     test2 = test1;
    //     std::cout << PURPLE "values test1" RESET << std::endl;
    //     for (int i = 0; i < test1.size(); i++)
    //         std::cout << test1[i] << std::endl;
    //     std::cout << PURPLE "values test2" RESET << std::endl;
    //     for (int i = 0; i < test2.size(); i++)
    //         std::cout << test2[i] << std::endl;
    //     std::cout << PURPLE "values test3" RESET << std::endl;
    //     for (int i = 0; i < test3.size(); i++)
    //         std::cout << test3[i] << std::endl;
    //     std::cout << PURPLE "change of values in test1" RESET << std::endl;
    //     for (int i = 0; i < test1.size(); i++)
    //     {
    //         test1[i] = "changed string";
    //         std::cout << test1[i] << std::endl;
    //     }
    //     std::cout << PURPLE "values test2" RESET << std::endl;
    //     for (int i = 0; i < test2.size(); i++)
    //         std::cout << test2[i] << std::endl;
    //     std::cout << PURPLE "values test3" RESET << std::endl;
    //     for (int i = 0; i < test3.size(); i++)
    //         std::cout << test3[i] << std::endl;
    //     std::cout << PURPLE "Destructors" RESET << std::endl;
    // }
    // {
    //     std::cout << RED "CONST TEST" RESET << std::endl;
    //     const Array<int> test(4);
    //     // test[0] = 1;
    //     // test[1] = 2;
    //     for (int i = 0; i < test.size(); i++)
    //         std::cout << test[i] << std::endl;
    // }
    return (0);
}
