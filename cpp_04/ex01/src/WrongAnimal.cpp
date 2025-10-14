/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 16:33:54 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type_ = ".";
}

WrongAnimal::WrongAnimal( std::string type )
{
	std::cout << "WrongAnimal constructor by parameter called" << std::endl;
	this->type_ = type;
}

WrongAnimal::WrongAnimal( WrongAnimal const & other )
{
	std::cout << "WrongAnimal constructor by copy called" << std::endl;
	*this = other;
}

WrongAnimal const& WrongAnimal::operator=( WrongAnimal const & a )
{
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
