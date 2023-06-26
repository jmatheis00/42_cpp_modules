/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/26 22:40:15 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    {
        std::cout << YELLOW "MUTANTSTACK TEST WITH INT" RESET << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        std::cout << PURPLE << "Element at top of stack container" RESET << std::endl;
        std::cout << mstack.top() << std::endl;

        mstack.pop();
        std::cout << PURPLE << "Size of stack container (pushed 2, popped 1)" RESET << std::endl;
        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << PURPLE << "Element order of underlying container" RESET << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << PURPLE << "Element order of stack container" RESET << std::endl;
        std::stack<int> s(mstack);
        while (s.empty() != true)
        {
            std::cout << s.top() << std::endl;
            s.pop();
        }
    }
    // {
        // can replace vector with deque or list
    //     std::cout << YELLOW "VECTOR TEST" RESET << std::endl;
    //     std::vector<int> mstack;

    //     mstack.push_back(5);
    //     mstack.push_back(17);
    //     std::cout << PURPLE << "Element at bottom of vector container" RESET << std::endl;
    //     std::cout << mstack.back() << std::endl;

    //     mstack.pop_back();
    //     std::cout << PURPLE << "Size of vector container (pushed 2, popped 1)" RESET << std::endl;
    //     std::cout << mstack.size() << std::endl;

    //     mstack.push_back(3);
    //     mstack.push_back(5);
    //     mstack.push_back(737);
    //     mstack.push_back(0);

    //     std::cout << PURPLE << "Elements of vector container" RESET << std::endl;
    //     std::vector<int>::iterator it = mstack.begin();
    //     std::vector<int>::iterator ite = mstack.end();

    //     ++it;
    //     --it;
    //     while (it != ite)
    //     {
    //         std::cout << *it << std::endl;
    //         ++it;
    //     }
    //     std::vector<int> s(mstack);
    // }
    {
        std::cout << YELLOW "MUTANTSTACK TEST WITH STRING" RESET << std::endl;
        MutantStack<std::string> mstack;
        mstack.push("Alpha");
        mstack.push("Beta");

        std::cout << PURPLE << "Element at top of stack container" RESET << std::endl;
        std::cout << mstack.top() << std::endl;

        mstack.pop();
        std::cout << PURPLE << "Size of stack container (pushed 2, popped 1)" RESET << std::endl;
        std::cout << mstack.size() << std::endl;

        mstack.push("THIRD");
        mstack.push("FOURTH");

        std::cout << PURPLE << "Element order of underlying container" RESET << std::endl;
        MutantStack<std::string>::const_iterator it = mstack.begin();
        MutantStack<std::string>::const_iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << PURPLE << "Element order of stack container" RESET << std::endl;
        std::stack<std::string> s(mstack);
        while (s.empty() != true)
        {
            std::cout << s.top() << std::endl;
            s.pop();
        }   
    }
    return 0;
}