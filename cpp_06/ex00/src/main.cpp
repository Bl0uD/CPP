/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:07:46 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/08 16:20:31 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int	main( int ac, char **av)
{
	if ( ac != 2 )
		std::cout << "Error : Run like this : \n./Conversion_of_scalar_types [input]" << std::endl;
	else
		ScalarConverter::convert( av[1] );
	return ( 0 );
}