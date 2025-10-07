/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:27:05 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/07 14:22:29 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cout << "try again : ./harl ['DEBUG', 'INFO', 'WARNING', 'ERROR']" << std::endl;
		return (1);
	}

	std::string av1(av[1]);
	if (!av[1] || av1.empty() || (av1 != "DEBUG" && av1 != "INFO" && av1 != "WARNING" && av1 != "ERROR"))
	{
		std::cout << "try again : ./harl ['DEBUG', 'INFO', 'WARNING', 'ERROR']" << std::endl;
		return (1);
	}

	Harl the_harl;
	the_harl.complain(av[1]);
	return (0);
}
