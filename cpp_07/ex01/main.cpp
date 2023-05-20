/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/20 14:49:00 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// int main(void)
// {
//     int a = 2;
//     int b = 3;

//     ::swap( a, b );
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

//     std::string c = "chaine1";
//     std::string d = "chaine2";

//     ::swap(c, d);
//     std::cout << "c = " << c << ", d = " << d << std::endl;
//     std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//     std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// return 0;
// }

class Awesome{
    public:
        Awesome(void): _n(42){return;}
        int get(void) const {return this->_n;}
    private:
        int _n;
};

std::ostream& operator<<(std::ostream& o, const Awesome &rhs) {o << rhs.get(); return o;}


template<typename T>
void print(T const& x) {std::cout << x << std::endl; return;}

int main()
{
    int tab[] = {0, 1, 2, 3, 4};
    Awesome tab2[5];

    iter(tab, 5, print<int>);
    iter(tab2, 5, print<Awesome>);

    return (0);
}