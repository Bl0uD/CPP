/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:59:43 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/07 01:23:42 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : _name( name ), _weaponType( weapon )
{
	std::cout << " ~ HumanA constructor called ~ " << std::endl;
}

HumanA::~HumanA()
{
	std::cout << " ~ HumanA destructor called ~ " << std::endl;
}

void	HumanA::attack( void ) const
{
	std::cout << _name << " attacks with their " << _weaponType.getType() << std::endl;
}
