/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:17 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/02 14:17:34 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
    private:
        std::string firstname_;
        std::string lastname_;
        std::string nickname_;
        std::string phonenumber_;
        std::string darkestsecret_;
    public:
        Contact();
        ~Contact();
        void set_firstname();
        void set_lastname();
        void set_nickname();
        void set_phonenumber();
        void set_darkestsecret();
        // void set_contactinfo(std::string info, std::string message);
        // void set_allinfos();
        std::string get_firstname();
        std::string get_lastname();
        std::string get_nickname();
        std::string get_phonenumber();
        std::string get_darkestsecret();
};

#endif