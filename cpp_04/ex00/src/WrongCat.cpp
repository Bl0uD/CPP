/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 16:23:09 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::~WrongCat()
{}

WrongCat::WrongCat()
{
	this->type_ = "WrongCat";
}

WrongCat::WrongCat( std::string name )
{
	this->type_ = "WrongCat";
	this->name_ = name;
}

WrongCat::WrongCat( WrongCat const & other ) : WrongAnimal ( other )
{
	*this = other;
}

WrongCat const& WrongCat::operator=( WrongCat const & a )
{
	this->name_ = a.name_;
	return ( *this );
}

std::string	WrongCat::getName( void ) const
{
	return ( this->name_ );
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat : MI-A-OU ! " << std::endl;
}
