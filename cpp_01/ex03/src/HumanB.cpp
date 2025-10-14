/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:59:43 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 17:48:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB( std::string name ) : name_( name )
{
	std::cout << " ~ HumanB constructor called ~ " << std::endl;
}

HumanB::~HumanB()
{
	std::cout << " ~ HumanB destructor called ~ " << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weaponType = &weapon;
}

void	HumanB::attack( void ) const
{
	std::cout << name_ << " attacks with their " << _weaponType->getType() << std::endl;
}
