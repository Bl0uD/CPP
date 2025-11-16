/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/17 00:12:12 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::~Brain()
{
	std::cout << "	🧨 Brain destructor called	🧨" << std::endl;
}

Brain::Brain()
{
	std::cout << "\t🔨 Brain default constructor called\t🔨" << std::endl;
}

Brain::Brain( Brain const & other )
{
	std::cout << "	🔨 Brain constructor by copy called	🔨" << std::endl;
	*this = other;
}

Brain const& Brain::operator=( Brain const & instance )
{
	int i = 0;
	
	if (this == &instance)
		return ( *this );
	while (i < 100)
	{
		this->_ideas[i] = instance._ideas[i];
		i++;
	}
	return ( *this );
}
