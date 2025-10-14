/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:57:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 17:47:45 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDhp_P
# define FIXEDhp_P

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_fixed_point;
		static const int _bits = 8;

	public:
		~Fixed();								// Canonical : Destructor
		Fixed();								// Canonical : Constructor
		Fixed( const int n );
		Fixed( const float n );
		Fixed( Fixed const& other );			// Canonical : Constructor
		Fixed & operator=( Fixed const & a );	// Canonical : Assign Operator '=' to Fixed
		
		bool operator>( Fixed const & a ) const;
		bool operator<( Fixed const & a ) const;
		bool operator>=( Fixed const & a) const;
		bool operator<=( Fixed const & a ) const;
		bool operator==( Fixed const & a ) const;
		bool operator!=( Fixed const & a ) const;
		
		Fixed operator+( Fixed const & a ) const;
		Fixed operator-( Fixed const & a ) const;
		Fixed operator*( Fixed const & a ) const;
		Fixed operator/( Fixed const & a ) const;

		Fixed & operator++( void );
		Fixed operator++( int );
		Fixed & operator--( void );
		Fixed operator--( int );
		
		int		getRaw_bits( void ) const;
		void	setRaw_bits( int const data );
		
		int		toInt( void ) const;
		float	toFloat( void ) const;
		
		static	Fixed const&	min(Fixed const& a, Fixed const& b);
		static	Fixed const&	max(Fixed const& a, Fixed const& b);
		static	Fixed&			min(Fixed& a, Fixed& b);
		static	Fixed&			max(Fixed& a, Fixed& b);
};

std::ostream& operator<<( std::ostream& os, Fixed const& a );

#endif
