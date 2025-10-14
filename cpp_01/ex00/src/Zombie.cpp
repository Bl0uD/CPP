/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:40:31 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 17:48:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : name_( name )
{
	std::cout << "Zombie " << this->name_ << " has spawned !" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << this->name_ << " is dead... 💀" << std::endl;
	return ;
}

void	Zombie::announce( void )
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
