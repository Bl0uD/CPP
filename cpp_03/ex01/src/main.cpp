/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:22:35 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 18:05:49 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ScavTrap.hpp"

int	main( void )
{
	ClapTrap	Bob("Bob");
	ScavTrap	Patrick("Patrick");
	int			i = 0;

	while (i < 13)
	{
		Bob.attack("Patrick");
		i++;
	}
	Patrick.takeDamage(53);
	Patrick.beRepaired(10);
	Patrick.guardGate();

	return (0);
}
