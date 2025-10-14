/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:22:35 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 14:50:20 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ScavTrap.hpp"
# include "../includes/FragTrap.hpp"

int	main( void )
{
	ClapTrap	Bob("Bob");
	ScavTrap	Patrick("Patrick");
	FragTrap	Petter("Petter");
	int			i = 0;

	while (i < 13)
	{
		Bob.attack("Patrick");
		i++;
	}
	
	Patrick.takeDamage(53);
	Patrick.beRepaired(10);
	Patrick.guardGate();

	Petter.highFivesGuys();
	Petter.attack("Niki");

	return (0);
}
