/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/17 00:14:00 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::~Cat()
{
	delete ( this->_brain );
	std::cout << "	🧨 Cat destructor called	🧨" << std::endl;
}

Cat::Cat() : Animal ( "Cat" ), name_ ( "Cat" )
{
	this->_brain = new Brain();
	std::cout << "	🔨 Cat default constructor called	🔨" << std::endl;
}

Cat::Cat( std::string name ) : Animal ( "Cat" ), name_ ( name )
{
	this->_brain = new Brain();
	std::cout << "	🔨 Cat constructor by parameter called	🔨" << std::endl;
}

Cat::Cat( Cat const & other ) : Animal ( other ), name_ ( other.name_ )
{
	this->_brain = new Brain(*other._brain);
	std::cout << "	🔨 Cat constructor by copy called	🔨" << std::endl;
}

Cat const& Cat::operator=( Cat const & a )
{
	if ( this != &a )
	{
		this->name_ = a.name_;
		*this->_brain = *a._brain;
	}
	return ( *this );
}

std::string	Cat::getName( void ) const
{
	return ( this->name_ );
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miaouuuuu ! " << std::endl;
}
