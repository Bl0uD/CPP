/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:57:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/13 16:34:30 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_fixed_point;
		static const int _bits = 8;

	public:
		Fixed();								// Canonical : Constructor
		Fixed( const int n );
		Fixed( const float n );
		Fixed( Fixed const& other );			// Canonical : Constructor
		~Fixed();								// Canonical : Destructor
		Fixed & operator=( Fixed const & a );	// Canonical : Assign Operator '=' to Fixed

		int		getRaw_bits( void ) const;
		void	setRaw_bits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;
	};

std::ostream& operator<<( std::ostream& os, Fixed const& a );

#endif
