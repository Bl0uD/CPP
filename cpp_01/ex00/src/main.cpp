/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:39:53 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/06 16:03:43 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main( void )
{
	Zombie	parent_zombie("parent_Zombie");

	Zombie *child_zombie;

	child_zombie = newZombie("child_Zombie");

	child_zombie->announce();
	parent_zombie.announce();

	randomChump("randow_zombie");

	delete child_zombie;
	return (0);
}
