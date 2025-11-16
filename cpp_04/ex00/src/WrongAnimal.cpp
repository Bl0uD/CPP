/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/17 00:18:19 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::~WrongAnimal()
{
	std::cout << "\t🧨 WrongAnimal destructor called\t🧨" << std::endl;
}

WrongAnimal::WrongAnimal() : type_ ( "WrongAnimal" )
{
	std::cout << "\t🔨 WrongAnimal default constructor called\t🔨" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type_ ( type )
{
	std::cout << "\t🔨 WrongAnimal constructor by parameter called\t🔨" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & other ) : type_ ( other.type_ )
{
	std::cout << "\t🔨 WrongAnimal constructor by copy called\t🔨" << std::endl;
}

WrongAnimal const& WrongAnimal::operator=( WrongAnimal const & a )
{
	if ( this != &a )
		this->type_ = a.type_;
	return ( *this );
}

std::string	WrongAnimal::getName( void ) const
{
	return ( "WrongAnimal : No name" );
}

std::string	WrongAnimal::getType( void ) const
{
	return ( this->type_ );
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal sound ! " << std::endl;
}
