/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 16:33:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type_ = "Dog";
}

Dog::Dog( std::string name )
{
	std::cout << "Dog constructor by parameter called" << std::endl;
	this->type_ = "Dog";
	this->name_ = name;
}

Dog::Dog( Dog const & other ) : Animal ( other )
{
	std::cout << "Dog constructor by copy called" << std::endl;
	*this = other;
}

Dog const& Dog::operator=( Dog const & a )
{
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
