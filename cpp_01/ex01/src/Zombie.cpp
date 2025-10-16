/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:56:45 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 15:20:27 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie( void )
{}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << this->name << " is dead... 💀" << std::endl;
}

void	Zombie::setName( std::string name)
{
	this->name = name;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
