/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:53:01 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 15:22:16 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int		i = 0;
	Zombie	*zombieHorde;

	if (N > 0)
	{
		zombieHorde = new Zombie[N];
		if (zombieHorde == NULL)
			return ( NULL );
		while (i < N)
			zombieHorde[i++].setName( name );
		return ( zombieHorde );
	}
	return ( NULL );
}
