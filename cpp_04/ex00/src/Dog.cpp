/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/16 14:37:47 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::~Dog()
{
	std::cout << "	🧨 Dog destructor called	🧨" << std::endl;
}

Dog::Dog() : name_ ( "Dog" )
{
	std::cout << "	🔨 Dog default constructor called	🔨" << std::endl;
}

Dog::Dog( std::string name ) : name_ ( name )
{
	std::cout << "	🔨 Dog constructor by parameter called	🔨" << std::endl;
}

Dog::Dog( Dog const & other ) : Animal ( other ), name_ ( other.name_ )
{
	std::cout << "	🔨 Dog constructor by copy called	🔨" << std::endl;
}

Dog const& Dog::operator=( Dog const & a )
{
	if ( this != &a )
		this->name_ = a.name_;
	return ( *this );
}

std::string	Dog::getName( void ) const
{
	return ( this->name_ );
}

void	Dog::makeSound( void ) const
{
	std::cout << "Waf Waf ! " << std::endl;
}
