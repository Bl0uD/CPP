/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/16 23:53:16 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::~Animal()
{
	std::cout << "	🧨 Animal destructor called	🧨" << std::endl;
}

Animal::Animal() : type_ ( "Animal" )
{
	std::cout << "	🔨 Animal default constructor called	🔨" << std::endl;
}

Animal::Animal( std::string type ) : type_ ( type )
{
	std::cout << "	🔨 Animal constructor by parameter called	🔨" << std::endl;
}

Animal::Animal( Animal const & other ) : type_ ( other.type_ )
{
	std::cout << "	🔨 Animal constructor by copy called	🔨" << std::endl;
}

Animal const& Animal::operator=( Animal const & a )
{
	if ( this != &a )
		this->type_ = a.type_;
	return ( *this );
}

std::string	Animal::getName( void ) const
{
	return ( "No name" );
}

std::string	Animal::getType( void ) const
{
	return ( this->type_ );
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal sound ! " << std::endl;
}
