/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:57:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/12 17:55:33 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	fixed_point;
		static const int bits = 8;

	public:
		Fixed();								// Canonical : Constructor
		Fixed( const int n );
		Fixed( const float n );
		Fixed( Fixed const& other );			// Canonical : Constructor
		~Fixed();								// Canonical : Destructor
		Fixed & operator=( Fixed const & a );	// Canonical : Assign Operator '=' to Fixed

		int		getRawBits( void ) const;
		void	setRawBits( int const data );
		
		int		toInt( void ) const;
		float	toFloat( void ) const;
	};

std::ostream& operator<<( std::ostream& os, Fixed const& a );

#endif
