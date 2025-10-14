/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 16:11:14 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::~Cat()
{}

Cat::Cat()
{
	this->type_ = "Cat";
}

Cat::Cat( std::string name )
{
	this->type_ = "Cat";
	this->name_ = name;
}

Cat::Cat( Cat const & other ) : Animal ( other )
{
	*this = other;
}

Cat const& Cat::operator=( Cat const & a )
{
	this->name_ = a.name_;
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
