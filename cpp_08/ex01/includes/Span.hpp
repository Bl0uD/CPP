/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:10:23 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/15 17:03:14 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
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
		void	addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end) ;
		int		shortestSpan();
		int		longestSpan();

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