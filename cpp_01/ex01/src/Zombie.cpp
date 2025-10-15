/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:56:45 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/15 16:01:34 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie( void )
{}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << this->name_ << " is dead... 💀" << std::endl;
}

void	Zombie::setName( std::string name)
{
	this->name_ = name;
}

void	Zombie::announce()
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
