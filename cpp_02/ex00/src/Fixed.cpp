/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:57:20 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 17:21:02 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed& Fixed::operator=( Fixed const& a )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = a.getRaw_bits();
	return (*this);
}

std::ostream& operator<<( std::ostream& os, Fixed const& a )
{
	os << a.getRaw_bits();
	return (os);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( void ) : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

int Fixed::getRaw_bits( void ) const
{
	 std::cout << "getRaw_bits called" << std::endl; 
	 return (this->_fixed_point); 
}

void Fixed::setRaw_bits( int const raw )
{
	std::cout << "setRaw_bits called" << std::endl; 
	this->_fixed_point = raw;
}
