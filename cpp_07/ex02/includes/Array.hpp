/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:56:25 by jdupuis           #+#    #+#             */
/*   Updated: 2026/04/17 11:33:23 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <stdexcept>
# include <iostream>
# include <string>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		~Array();
		Array();
		Array( unsigned int n );
		Array( const Array &copy );
		Array &operator=( const Array &instance );
		T &operator[](unsigned int n);
		const T &operator[](unsigned int n) const;
		unsigned int size( void ) const;
};

# include "../src/Array.tpp"

#endif