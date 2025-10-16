/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:59:43 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 15:28:13 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : name( name ), type( weapon )
{
	std::cout << " ~ HumanA constructor called ~ " << std::endl;
}

HumanA::~HumanA()
{
	std::cout << " ~ HumanA destructor called ~ " << std::endl;
}

void	HumanA::attack( void ) const
{
	std::cout << name << " attacks with their " << type.getType() << std::endl;
}
