/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:08:08 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/28 19:08:11 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::~PmergeMe( void )
{
	std::cout << "PmergeMe destructor called." << std::endl;
}

PmergeMe::PmergeMe( void )
{
	std::cout << "PmergeMe default constructor called." << std::endl;
	
}

PmergeMe::PmergeMe(  ) : 
{
	std::cout << "PmergeMe parametric constructor called." << std::endl;
}

PmergeMe::PmergeMe( PmergeMe const &copy )
{
	std::cout << "PmergeMe copy constructor called." << std::endl;
	*this = copy;
}

PmergeMe	&PmergeMe::operator=( PmergeMe const &instance )
{
	
	return ( *this );
}

