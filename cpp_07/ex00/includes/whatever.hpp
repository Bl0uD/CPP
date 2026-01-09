/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:29:59 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/10 00:39:46 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <typename T>
T const &max( T const &a, T const &b )
{
	if ( a > b )
		return ( a );
	else
		return ( b );
}

template <typename T>
T const &min( T const &a, T const &b )
{
	if ( a < b )
		return ( a );
	else
		return ( b );
}

template <typename T>
void swap( T &a, T &b )
{
	T tmp = a;
	a = b;
	b = tmp;
}

#endif