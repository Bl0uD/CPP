/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:57:20 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/11 00:05:06 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed& Fixed::operator=(Fixed const& a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = a.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Fixed const& a)
{
	os << a.getRawBits();
	return (os);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(void) : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

int Fixed::getRawBits(void) const
{
	 std::cout << "getRawBits called" << std::endl; 
	 return (this->fixed_point); 
}

void Fixed::setRawBits(int const data)
{
	std::cout << "setRawBits called" << std::endl; 
	this->fixed_point = data;
}
