/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:15:33 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/06 16:33:21 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main( void )
{
	int	i = 0;
	int	nb_Horde = 3;
	Zombie *ZombieHorde;
	
	ZombieHorde = zombieHorde(nb_Horde, "BOB");
	while ( i < nb_Horde)
		ZombieHorde[i++].announce();
	delete[] ZombieHorde;
	return (0);
}
