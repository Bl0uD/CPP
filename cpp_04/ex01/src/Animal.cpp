/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 16:31:53 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type_ = ".";
}

Animal::Animal( std::string type )
{
	std::cout << "Animal constructor by parameter called" << std::endl;
	this->type_ = type;
}

Animal::Animal( Animal const & other )
{
	std::cout << "Animal constructor by copy called" << std::endl;
	*this = other;
}

Animal const& Animal::operator=( Animal const & a )
{
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
