/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:57:20 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 15:58:48 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ) : _fixed_point ( 0 )
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n )
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = n << this->_bits;
}

Fixed::Fixed( const float n ) : _fixed_point ( roundf(n * (1 << this->_bits)) )
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& other )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=( Fixed const& a )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = a.getRaw_bits();
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Fixed const& a )
{
	os << a.toFloat();
	return ( os );
}

bool	Fixed::operator>( Fixed const& a ) const
{
	return ( this->_fixed_point > a.getRaw_bits() );
}

bool	Fixed::operator<( Fixed const& a ) const
{
	return ( this->_fixed_point < a.getRaw_bits() );
}

bool	Fixed::operator<=( Fixed const& a ) const
{
	return ( this->_fixed_point <= a.getRaw_bits() );
}

bool	Fixed::operator>=( Fixed const& a ) const
{
	return ( this->_fixed_point >= a.getRaw_bits() );
}

bool	Fixed::operator==( Fixed const& a ) const
{
	return ( this->_fixed_point == a.getRaw_bits() );
}

bool	Fixed::operator!=( Fixed const& a ) const
{
	return ( this->_fixed_point != a.getRaw_bits() );
}

Fixed	Fixed::operator+( Fixed const& a ) const
{
	Fixed	newFixed;

	newFixed.setRaw_bits( this->_fixed_point + a._fixed_point );
	return ( newFixed );
}

Fixed 	Fixed::operator-( Fixed const& a ) const
{
	Fixed	newFixed;

	newFixed.setRaw_bits( this->_fixed_point - a._fixed_point );
	return ( newFixed );
}

Fixed 	Fixed::operator*( Fixed const& a ) const
{
	Fixed	newFixed;

	newFixed.setRaw_bits( (this->_fixed_point * a._fixed_point) >> this->_bits);
	return ( newFixed );
}

Fixed	Fixed::operator/( Fixed const& a ) const
{
	Fixed	newFixed;

	newFixed.setRaw_bits( (this->_fixed_point << this->_bits) / a._fixed_point );
	return ( newFixed );
}

Fixed& 	Fixed::operator++( void )
{
	this->_fixed_point++;
	return ( *this );
}

Fixed	 Fixed::operator++( int )
{
	Fixed	newFixed( *this );
	
	this->_fixed_point++;
	return ( newFixed );
}

Fixed&	Fixed::operator--( void )
{
	this->_fixed_point--;
	return ( *this );
}

Fixed	Fixed::operator--( int )
{
	Fixed	newFixed( *this );
	
	this->_fixed_point--;
	return ( newFixed );
}

int	Fixed::getRaw_bits( void ) const
{
	return ( this->_fixed_point );
}

void	Fixed::setRaw_bits( int const data )
{
	this->_fixed_point = data;
}

int	Fixed::toInt( void ) const
{
	return ( (int)this->_fixed_point >> this->_bits );
}

float	Fixed::toFloat( void ) const
{
	return ( (float)this->_fixed_point / (1 << this->_bits) );
}

Fixed const	&Fixed::max( Fixed const& a, Fixed const& b )
{
	if ( a._fixed_point > b._fixed_point )
		return ( a );
	return ( b );
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	if ( a._fixed_point > b._fixed_point )
		return ( a );
	return ( b );
}

Fixed const	&Fixed::min( Fixed const& a, Fixed const& b )
{
	if ( a._fixed_point < b._fixed_point )
		return ( a );
	return ( b );
}

Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	if ( a._fixed_point < b._fixed_point )
		return ( a );
	return ( b );
}
