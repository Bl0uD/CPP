/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:30:19 by jdupuis           #+#    #+#             */
/*   Updated: 2026/04/17 11:51:38 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <algorithm>

template <typename T>
typename T::iterator easyfind( T &container, int n )
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	
	if ( it == container.end() )
		throw NotFoundExeption();
	
	return ( it );
}

template <typename T>
typename T::const_iterator easyfind( const T &container, int n )
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);

	if ( it == container.end() )
		throw NotFoundExeption();

	return ( it );
}