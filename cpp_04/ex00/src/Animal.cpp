/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/17 00:18:19 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::~Animal()
{
	std::cout << "\t🧨 Animal destructor called\t🧨" << std::endl;
}

Animal::Animal() : type_ ( "Animal" )
{
	std::cout << "\t🔨 Animal default constructor called\t🔨" << std::endl;
}

Animal::Animal( std::string type ) : type_ ( type )
{
	std::cout << "\t🔨 Animal constructor by parameter called\t🔨" << std::endl;
}

Animal::Animal( Animal const & other ) : type_ ( other.type_ )
{
	std::cout << "\t🔨 Animal constructor by copy called\t🔨" << std::endl;
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
