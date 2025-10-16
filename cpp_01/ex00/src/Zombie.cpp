/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:40:31 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 15:19:33 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : name( name )
{
	std::cout << "Zombie " << this->name << " has spawned !" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << this->name << " is dead... 💀" << std::endl;
	return ;
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
