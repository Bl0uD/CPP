/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:57:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/11 14:56:08 by jdupuis          ###   ########.fr       */
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
		~Fixed();								// Canonical : Destructor
		Fixed();								// Canonical : Constructor
		Fixed(Fixed const& other);				// Canonical : Constructor
		Fixed & operator=(Fixed const & a);		// Canonical : Assign Operator '=' to Fixed

		int		getRawBits(void) const;
		void	setRawBits(int const data);

};

std::ostream& operator<<(std::ostream& os, Fixed const& a);

#endif
