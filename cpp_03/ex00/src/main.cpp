/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:22:35 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/16 13:12:21 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ClapTrap.hpp"

int	main( void )
{
	ClapTrap	Bob("Bob");
	ClapTrap	Patrick("Patrick");
	int			i = 0;

	while (i < 13)
	{
		Bob.attack("Patrick");
		i++;
	}
	
	Bob.beRepaired(5);
	Bob.takeDamage(10);
	ClapTrap	Neo(Bob);
	Neo.takeDamage(10);
	
	return (0);
}
