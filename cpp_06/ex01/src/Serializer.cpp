/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:05:53 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/09 16:32:39 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::~Serializer() {};

Serializer::Serializer() {};

Serializer::Serializer( std::string ) {};

Serializer::Serializer( Serializer const &copy )
{
	*this = copy;
};

Serializer &Serializer::operator=( Serializer const &instance )
{
	(void)instance;
	return ( *this );
}

uintptr_t Serializer::serialize( Data* ptr )
{
	uintptr_t ser_data = reinterpret_cast<uintptr_t>(ptr);
	return ( ser_data );
}

Data *Serializer::deserialize( uintptr_t raw )
{
	Data *ptr_data = reinterpret_cast<Data*>(raw);
	return ( ptr_data );
}
