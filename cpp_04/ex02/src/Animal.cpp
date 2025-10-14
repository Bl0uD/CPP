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
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
	this->type_ = ".";
}

AAnimal::AAnimal( std::string type )
{
	std::cout << "AAnimal constructor by parameter called" << std::endl;
	this->type_ = type;
}

AAnimal::AAnimal( AAnimal const & other )
{
	std::cout << "AAnimal constructor by copy called" << std::endl;
	*this = other;
}

AAnimal const& AAnimal::operator=( AAnimal const & a )
{
	this->type_ = a.type_;
	return ( *this );
}

std::string	AAnimal::getName( void ) const
{
	return ( "No name" );
}

std::string	AAnimal::getType( void ) const
{
	return ( this->type_ );
}

void	AAnimal::makeSound( void ) const
{
	std::cout << "AAnimal sound ! " << std::endl;
}
