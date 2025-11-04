/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:57:20 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/04 19:55:14 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed& Fixed::operator=( Fixed const& a )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = a.getRaw_bits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Fixed const& a)
{
	os << a.toFloat();
	return (os);
}

Fixed::Fixed( void ) : _fixed_point (0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n )
{
	if (n <= (INT_MAX / (1 << _bits)) && n >= (INT_MIN / (1 << _bits)))
		_fixed_point = n << this->_bits;
	else
	{
		_fixed_point = 0;
		std::cout << "Warning: Int value " << n << " is out of range for " 
			<< _bits << "-bit fixed-point representation, set to 0" << std::endl;	}	
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n )
{
	if (n <= INT_MAX / (1 << _bits) && n >= INT_MIN / (1 << _bits))
		_fixed_point = roundf( n * (1 << this->_bits) );
	else
	{
		_fixed_point = 0;
		std::cout << "Warning: Float value " << n << " is out of range for " 
			<< _bits << "-bit fixed-point representation, set to 0" << std::endl;
	}
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRaw_bits( void ) const
{
	return (this->_fixed_point);
}

void	Fixed::setRaw_bits( int const raw )
{
	this->_fixed_point = raw;
}

int	Fixed::toInt( void ) const
{
	return ( (int)this->_fixed_point >> this->_bits );
}

float	Fixed::toFloat( void ) const
{
	return ( (float)this->_fixed_point / (1 << this->_bits) );
}
