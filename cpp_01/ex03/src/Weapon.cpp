/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:59:11 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 15:30:48 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon( std::string type ) : type( type )
{
	std::cout << " ~ Weapon constructor called ~ " << std::endl;
}

Weapon::~Weapon()
{
	std::cout << " ~ Weapon destructor called ~ " << std::endl;
}

std::string	Weapon::getType( void ) const
{
	return (type);
}

void	Weapon::setType( std::string type )
{
	type = type;
}
