/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:57:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/10 23:56:52 by jdupuis          ###   ########.fr       */
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
		~Fixed();								// Destructor
		Fixed();								// Constructor
		Fixed(Fixed const& other);				// Constructor
		Fixed & operator=(Fixed const & a);		// Assign Operator '=' to Fixed
		int		getRawBits(void) const;
		void	setRawBits(int const data);

};

std::ostream& operator<<(std::ostream& os, Fixed const& a);

#endif
