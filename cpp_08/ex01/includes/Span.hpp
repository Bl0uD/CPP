/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:10:23 by jdupuis           #+#    #+#             */
/*   Updated: 2026/04/17 11:51:38 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>
# include <exception>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_v;

	public:
		~Span();
		Span();
		Span( unsigned int N );
		Span( const Span &copy );
		Span &operator=( const Span &instance );

		void	addNumber( int n );

		template <typename InputIt>
		void	addMultipleNumbers( InputIt begin, InputIt end )
		{
			const std::size_t rangeSize = static_cast<std::size_t>(std::distance(begin, end));

			if ( this->_v.size() + rangeSize > this->_N )
				throw FullContainerException();
			this->_v.insert( this->_v.end(), begin, end );
		}

		int		shortestSpan() const;
		int		longestSpan() const;

		class 	FullContainerException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ( "Container is full" );
				}
		};
		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ( "Not enough number is container" );
				}
		};
};

#endif