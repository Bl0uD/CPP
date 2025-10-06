/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:59:11 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/06 18:20:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon( std::string type ) : _type( type )
{
	std::cout << " ~ Weapon constructor called ~ " << std::endl;
}

Weapon::~Weapon()
{
	std::cout << " ~ Weapon destructor called ~ " << std::endl;
}

std::string	Weapon::getType( void ) const
{
	return (_type);
}

void	Weapon::setType( std::string type )
{
	_type = type;
}
