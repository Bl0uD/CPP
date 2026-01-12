/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:56:25 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/10 00:58:41 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename>

class Array
{
	private:
		T				*_array;
		unsigend int	_size;

	public:
		~Array();
		Array();
		Array( unsigned int n );
		Array( const Array &copy );
		Array &operator=( const Array &instance );

		
};

#endif