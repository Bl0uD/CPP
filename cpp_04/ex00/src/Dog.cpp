/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/17 00:18:19 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::~Dog()
{
	std::cout << "\t🧨 Dog destructor called\t🧨" << std::endl;
}

Dog::Dog() : Animal ( "Dog" ), name_ ( "Dog" )
{
	std::cout << "\t🔨 Dog default constructor called\t🔨" << std::endl;
}

Dog::Dog( std::string name ) : Animal ( "Dog" ), name_ ( name )
{
	std::cout << "\t🔨 Dog constructor by parameter called\t🔨" << std::endl;
}

Dog::Dog( Dog const & other ) : Animal ( other ), name_ ( other.name_ )
{
	std::cout << "\t🔨 Dog constructor by copy called\t🔨" << std::endl;
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
