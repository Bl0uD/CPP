/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:10:44 by jdupuis           #+#    #+#             */
/*   Updated: 2026/04/17 11:51:38 by jdupuis          ###   ########.fr       */
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

int		Span::shortestSpan() const
{
	if ( this->_v.size() <= 1 )
		throw NotEnoughNumbersException();

	std::vector<int>	tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());

	long long			min = static_cast<long long>(tmp[1]) - static_cast<long long>(tmp[0]);
	unsigned int		i = 2;
	
	while ( i < tmp.size() )
	{
		const long long current = static_cast<long long>(tmp[i]) - static_cast<long long>(tmp[i - 1]);
		if (current < min)
			min = current;
		i++;
	}
	
	return ( static_cast<int>(min) );
}

int		Span::longestSpan() const
{
	if ( this->_v.size() <= 1 )
		throw NotEnoughNumbersException();
	
	std::vector<int>	tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());

	return ( static_cast<int>(static_cast<long long>(tmp[tmp.size() - 1]) - static_cast<long long>(tmp[0])) );
}