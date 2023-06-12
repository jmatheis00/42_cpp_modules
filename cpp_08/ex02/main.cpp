/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/12 17:04:40 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    {
        std::cout << YELLOW "MUTANTSTACK TEST" RESET << std::endl;
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

        std::cout << PURPLE << "Elements of stack container" RESET << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
        std::cout << YELLOW "COPYTEST MUTANTSTACK TEST" RESET << std::endl;
        std::cout << PURPLE "COPY CONSTRUCTOR" RESET << std::endl;
        MutantStack<int> test1 = mstack;
        std::cout << PURPLE "COPY ASSIGNMENT OPERATOR" RESET << std::endl;
        MutantStack<int> test2;
        test2.push(1111);
        test2 = mstack;

        mstack.pop();
        mstack.push(111);
        mstack.push(222);
        mstack.push(333);
        std::cout << PURPLE "Elements mstack after change" RESET << std::endl;
        it = mstack.begin();
        ite = mstack.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }       
        std::cout << PURPLE "Elements test1" RESET << std::endl;
        MutantStack<int>::iterator beg_1 = test1.begin();
        MutantStack<int>::iterator end_1 = test1.end();
        ++beg_1;
        --beg_1;
        while (beg_1 != end_1)
        {
            std::cout << *beg_1 << std::endl;
            ++beg_1;
        }
        std::cout << PURPLE "Elements test2" RESET << std::endl;
        MutantStack<int>::iterator beg_2 = test2.begin();
        MutantStack<int>::iterator end_2 = test2.end();
        ++beg_2;
        --beg_2;
        while (beg_2 != end_2)
        {
            std::cout << *beg_2 << std::endl;
            ++beg_2;
        }
    }
    {
        std::cout << YELLOW "LIST TEST" RESET << std::endl;
        std::list<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << PURPLE << "Element at bottom of list container" RESET << std::endl;
        std::cout << mstack.back() << std::endl;

        mstack.pop_back();
        std::cout << PURPLE << "Size of list container (pushed 2, popped 1)" RESET << std::endl;
        std::cout << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);

        std::cout << PURPLE << "Elements of list container" RESET << std::endl;
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
    }
   {
        std::cout << YELLOW "VECTOR TEST" RESET << std::endl;
        std::vector<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << PURPLE << "Element at bottom of vector container" RESET << std::endl;
        std::cout << mstack.back() << std::endl;

        mstack.pop_back();
        std::cout << PURPLE << "Size of vector container (pushed 2, popped 1)" RESET << std::endl;
        std::cout << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);

        std::cout << PURPLE << "Elements of vector container" RESET << std::endl;
        std::vector<int>::iterator it = mstack.begin();
        std::vector<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::vector<int> s(mstack);
    }
    {
        std::cout << YELLOW "DEQUE TEST" RESET << std::endl;
        std::deque<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << PURPLE << "Element at bottom of deque container" RESET << std::endl;
        std::cout << mstack.back() << std::endl;

        mstack.pop_back();
        std::cout << PURPLE << "Size of deque container (pushed 2, popped 1)" RESET << std::endl;
        std::cout << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);

        std::cout << PURPLE << "Elements of deque container" RESET << std::endl;
        std::deque<int>::iterator it = mstack.begin();
        std::deque<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::deque<int> s(mstack);
    }
    return 0;
}