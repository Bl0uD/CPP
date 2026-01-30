/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:10:44 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/30 14:49:56 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::~Span( void )
{
	std::cout << "Span destructor called." << std::endl;
}

Span::Span( void ) : _N ( 0 )
{
	std::cout << "Span default constructor called." << std::endl;
}

Span::Span( unsigned int N )  : _N ( N )
{
	std::cout << "Span parametric constructor called." << std::endl;
}

Span::Span( Span const &copy )
{
	std::cout << "Span copy constructor called." << std::endl;
	*this = copy;
}

Span	&Span::operator=( Span const &instance )
{
	if ( this != &instance )
	{
		this->_N = instance._N;
		this->_v = instance._v;
	}
	return ( *this );
}

void	Span::addNumber( int n )
{
	if ( this->_v.size() >= this->_N )
		throw FullContainerException();
	this->_v.push_back( n );
}

void	Span::addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
	if ( _v.size() + std::distance(begin, end) > _N )
		throw FullContainerException();
	_v.insert( _v.end(), begin, end );
}

int		Span::shortestSpan()
{
	if ( this->_v.size() <= 1 )
		throw NotEnoughNumbersException();

	std::vector<int>	tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());

	int					min = tmp[1] - tmp[0];
	unsigned int		i = 2;
	
	while ( i < tmp.size() )
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
		i++;
	}
	
	return ( min );
}

int		Span::longestSpan()
{
	if ( this->_v.size() <= 1 )
		throw NotEnoughNumbersException();
	
	std::vector<int>	tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());

	return ( tmp[tmp.size() - 1] - tmp[0] );
}