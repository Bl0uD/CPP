/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 17:31:31 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::~AAnimal()
{
	std::cout << "\t🧨 AAnimal destructor called\t🧨" << std::endl;
}

AAnimal::AAnimal() : type_ ( "AAnimal" )
{
	std::cout << "\t🔨 AAnimal default constructor called\t🔨" << std::endl;
}

AAnimal::AAnimal( std::string type ) : type_ ( type )
{
	std::cout << "\t🔨 AAnimal constructor by parameter called\t🔨" << std::endl;
}

AAnimal::AAnimal( AAnimal const & other ) : type_ ( other.type_ )
{
	std::cout << "\t🔨 AAnimal constructor by copy called\t🔨" << std::endl;
}

AAnimal const& AAnimal::operator=( AAnimal const & a )
{
	if ( this != &a )
		this->type_ = a.type_;
	return ( *this );
}

std::string	AAnimal::getType( void ) const
{
	return ( this->type_ );
}
