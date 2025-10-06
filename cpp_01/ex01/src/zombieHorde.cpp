/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:53:01 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/06 16:25:59 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int		i = 0;
	Zombie	*zombieHorde;

	zombieHorde = new Zombie[N];
	if (zombieHorde == NULL)
		return ( NULL );
	while (i < N)
		zombieHorde[i++].setName( name );
	return ( zombieHorde );
}
