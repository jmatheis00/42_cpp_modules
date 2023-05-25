/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/25 13:06:39 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
    std::cout << YELLOW "INT TEST" RESET << std::endl;
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << YELLOW "STRING TEST" RESET << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    
    std::cout << YELLOW "CHAR TEST" RESET << std::endl;
    char e = 'a';
    char f = 'b';
    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
    std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

    return 0;
}

// class Awesome{
//     public:
//         Awesome(void): _n(0){}
//         Awesome(int n): _n(n){}
//         Awesome& operator=(Awesome& a) {_n = a._n; return *this;}
//         bool operator==(Awesome const & rhs) const {return (this->_n == rhs._n);}
//         bool operator!=(Awesome const & rhs) const {return (this->_n != rhs._n);}
//         bool operator>(Awesome const & rhs) const {return (this->_n > rhs._n);}
//         bool operator<(Awesome const & rhs) const {return (this->_n < rhs._n);}
//         bool operator>=(Awesome const & rhs) const {return (this->_n >= rhs._n);}
//         bool operator<=(Awesome const & rhs) const {return (this->_n <= rhs._n);}

//         int get_n() const {return _n;}
        
//     private:
//         int _n;
// };

// std::ostream& operator<<(std::ostream& o, const Awesome &a) {o << a.get_n(); return o;}


// int main()
// {
//     Awesome a(2), b(4);

//     swap(a, b);
//     std::cout << a << " " << b << std::endl;
//     std::cout << max(a,b) << std::endl;
//     std::cout << min(a,b) << std::endl;
//     return (0);
// }