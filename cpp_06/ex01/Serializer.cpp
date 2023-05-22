/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:42:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/22 13:12:52 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer &copyclass)
{
	(void)copyclass;
}

Serializer& Serializer::operator= (const Serializer& copyop)
{
	if (this != &copyop)
	{

	}
	return(*this);
}

Serializer::~Serializer()
{
	
}

// OTHER MEMBER FUNCTIONS

uintptr_t Serializer::serialize(Data* ptr)
{
	std::cout << RED "*** seralize ***" RESET << std::endl;
	uintptr_t u = reinterpret_cast<uintptr_t>(ptr);
	return(u);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	std::cout << RED "*** deserialize ***" RESET << std::endl;
	struct Data* d = reinterpret_cast<Data*>(raw);
	return(d);
}