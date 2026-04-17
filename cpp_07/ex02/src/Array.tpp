/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:53:46 by jdupuis           #+#    #+#             */
/*   Updated: 2026/04/17 11:33:23 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

template <typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template <typename T>
Array<T>::Array() : _array( NULL ), _size ( 0 )
{}

template <typename T>
Array<T>::Array( unsigned int n ) : _array( new T[n]() ), _size ( n )
{}

template <typename T>
Array<T>::Array( const Array &copy ) : _array( new T[copy._size] ), _size( copy._size )
{
	unsigned int	i = 0;

	while ( i < _size )
	{
		_array[i] = copy._array[i];
		i++;
	}
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &instance)
{
	if ( this != &instance )
	{
		T		*newArray = new T[instance._size];
		unsigned int i = 0;
		while (i < instance._size)
		{
			newArray[i] = instance._array[i];
			i++;
		}
		delete [] this->_array;
		this->_array = newArray;
		this->_size = instance._size;
	}
	return ( *this );
}

template <typename T>
T &Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw std::out_of_range("out of bound, my dear");
	return ( _array[n] ); 
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const
{
	if (n >= _size) 
		throw std::out_of_range("out of bound, my dear");
	return ( _array[n] );
}

template <typename T>
unsigned int Array<T>::size( void ) const
{
	return ( _size );
}
