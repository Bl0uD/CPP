/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/16 14:38:17 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::~WrongCat()
{
	std::cout << "	🧨 WrongCat destructor called	🧨" << std::endl;
}

WrongCat::WrongCat() : name_ ( "WrongCat" )
{
	std::cout << "	🔨 WrongCat default constructor called	🔨" << std::endl;
}

WrongCat::WrongCat( std::string name ) : name_ ( name )
{
	std::cout << "	🔨 WrongCat constructor by parameter called	🔨" << std::endl;
}

WrongCat::WrongCat( WrongCat const & other ) : WrongAnimal ( other ), name_ ( other.name_ )
{
	std::cout << "	🔨 WrongCat constructor by copy called	🔨" << std::endl;
}

WrongCat const& WrongCat::operator=( WrongCat const & a )
{
	if ( this != &a )
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
