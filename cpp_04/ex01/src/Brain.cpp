/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 17:35:51 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain( std::string )
{
	std::cout << "Brain constructor by parameter called" << std::endl;
}

Brain::Brain( Brain const & other )
{
	std::cout << "Brain constructor by copy called" << std::endl;
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
