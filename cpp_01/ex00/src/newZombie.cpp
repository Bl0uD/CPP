/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:40:42 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/06 16:01:34 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie *newZombie;
	
	newZombie = new Zombie(name);
	if (newZombie == NULL)
		return NULL;
	return (newZombie);
}
