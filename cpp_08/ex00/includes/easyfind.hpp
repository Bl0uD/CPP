/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:27:42 by jdupuis           #+#    #+#             */
/*   Updated: 2026/04/17 11:51:38 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <exception>

class NotFoundExeption : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Number not found");
		}
};

template <typename T>
typename T::iterator easyfind( T &container, int n );

template <typename T>
typename T::const_iterator easyfind( const T &container, int n );

# include "../src/easyfind.tpp"

#endif