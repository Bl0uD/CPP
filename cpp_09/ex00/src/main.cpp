/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 00:26:36 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/19 20:10:36 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int	main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cout << "Usage: ./btc [file]" << std::endl;
		return ( 1 );
	}

	try
	{
		BitcoinExchange exchange;
		exchange.execute( av[1] );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}

	return ( 0 );
}
