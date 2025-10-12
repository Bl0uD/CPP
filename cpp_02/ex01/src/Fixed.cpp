/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:57:20 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/12 17:56:51 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed& Fixed::operator=( Fixed const& a )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = a.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Fixed const& a)
{
	os << a.toFloat();
	return (os);
}

Fixed::Fixed( void ) : fixed_point (0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n )
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = n << this->bits;
}

Fixed::Fixed( const float n )
{
	std::cout << "Float constructor called" << std::endl;
	float scaled = n * ( 1 << this->bits );
	this->fixed_point = (int)(scaled + (scaled >= 0 ? 0.5f : -0.5f));
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

int	Fixed::getRawBits( void ) const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits( int const data )
{
	this->fixed_point = data;
}

int	Fixed::toInt( void ) const
{
	return ( (int)this->fixed_point >> this->bits );
}

float	Fixed::toFloat( void ) const
{
	return ( (float)this->fixed_point / (1 << this->bits) );
}
