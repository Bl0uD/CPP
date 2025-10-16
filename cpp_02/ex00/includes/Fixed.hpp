/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:57:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 17:25:43 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixed_point;
		static const int	_bits = 8;

	public:
		~Fixed( void );								// Canonical : Destructor
		Fixed( void );								// Canonical : Constructor
		Fixed( Fixed const& other );				// Canonical : Constructor
		Fixed & operator=( Fixed const & a );		// Canonical : Assign Operator '=' to Fixed

		int		getRaw_bits( void ) const;
		void	setRaw_bits( int const raw );

};

std::ostream& operator<<( std::ostream& os, Fixed const& a );

#endif
