/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:59:43 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 15:30:06 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB( std::string name ) : name( name ), type( NULL )
{
	std::cout << " ~ HumanB constructor called ~ " << std::endl;
}

HumanB::~HumanB()
{
	std::cout << " ~ HumanB destructor called ~ " << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->type = &weapon;
}

void	HumanB::attack( void ) const
{
	if ( this->type )
		std::cout << name << " attacks with their " << type->getType() << std::endl;
	else
		std::cout << name << " attacks with their hands (no weapon)" << std::endl;

}
