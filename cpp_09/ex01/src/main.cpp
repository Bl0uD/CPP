/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:57:25 by jdupuis           #+#    #+#             */
/*   Updated: 2026/02/06 16:48:21 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int	main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cout << "Usage: ./RPN \"3 4 +\"" << std::endl;
		return ( 1 );
	}
	try
	{
		RPN	rpn( av[1] );
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what() << std::endl;
		return ( 1 );
	}
	return ( 0 );
}