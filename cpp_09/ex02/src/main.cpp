/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:07:43 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/30 15:58:56 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main( int ac, char **av )
{
	if ( ac == 1 )
	{
		std::cout << "Usage: ./PmergeMe [positive integer sequence]" << std::endl;
		return ( 1 );
	}

	try
	{
		PmergeMe sort( av + 1 );
		sort.execute();
	}
	catch( const std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}

	return ( 0 );
}